#include <ble_stack_handler_types.h>

void nrf_err_check(unsigned int loc, unsigned int err_code) {
    if(err_code != 0) {
        Serial.print("err_code = ");
        Serial.println(err_code, HEX);
        Serial.println(loc, DEC);
        while(1);
    }
}
static void softdevice_assertion_handler(uint32_t pc, uint16_t line_num, const uint8_t * file_name) {
  Serial.println("softdevice_assertion_handler");
}

#define CFG_GAP_LOCAL_NAME "nRF5x"
#define msec_to_1_25msec(interval_ms) ((interval_ms * 4) / 5)

void advertiseBeacon() {
    nrf_err_check(10, sd_softdevice_enable(8, softdevice_assertion_handler));
    nrf_err_check(11, sd_nvic_EnableIRQ(SWI2_IRQn));
    
    // --
    
    ble_gap_conn_sec_mode_t sec_mode;
    
    BLE_GAP_CONN_SEC_MODE_SET_OPEN(&sec_mode); // no security is needed

    nrf_err_check(1, sd_ble_gap_device_name_set(&sec_mode, (const uint8_t *) CFG_GAP_LOCAL_NAME, strlen(CFG_GAP_LOCAL_NAME)));
    nrf_err_check(2, sd_ble_gap_appearance_set(BLE_APPEARANCE_GENERIC_TAG));
    
    // --
    
    ble_gap_conn_params_t gap_conn_params;

    gap_conn_params.min_conn_interval = msec_to_1_25msec(100);  // in 1.25ms units
    gap_conn_params.max_conn_interval = msec_to_1_25msec(500);  // in 1.25ms unit
    gap_conn_params.slave_latency     = 0;
    gap_conn_params.conn_sup_timeout  = 4000 / 10; // in 10ms unit
    
    nrf_err_check(3, sd_ble_gap_ppcp_set(&gap_conn_params));
    
    // --
    
    nrf_err_check(4, sd_ble_gap_tx_power_set(4));

    // ---

    static ble_gap_conn_params_t  m_preferred_conn_params;  /**< Connection parameters preferred by the application. */
    
    nrf_err_check(5, sd_ble_gap_ppcp_get(&m_preferred_conn_params));

    // ---

    uint8_t p_data[] = { 0x02, 0x01, 0x04, 0x1A, 0xFF, 0x4C, 0x00, 0x02, 0x15, 0xE3, 0xC5, 0x6D, 0xB5, 0xDF, 0xFB, 0x48, 0xD2, 0xB0, 0x60, 0xD0, 0xF5, 0xA7, 0x10, 0x96, 0xE0, 0x00, 0x00, 0x00, 0x00, 0xC8 };

    nrf_err_check(6, sd_ble_gap_adv_data_set(p_data, 30, NULL, 0));
    nrf_err_check(7, sd_ble_gap_appearance_set(BLE_APPEARANCE_GENERIC_TAG));

    // ---

    ble_gap_adv_params_t adv_para = {0};

    adv_para.type        = BLE_GAP_ADV_TYPE_ADV_NONCONN_IND;
    adv_para.p_peer_addr = NULL; // Undirected advertisement
    adv_para.fp          = BLE_GAP_ADV_FP_ANY;
    adv_para.p_whitelist = NULL;
    adv_para.interval    = 160; // advertising interval (in units of 0.625 ms)
    adv_para.timeout     = 0;

    nrf_err_check(8, sd_ble_gap_adv_start(&adv_para));
    
    // --
    
    Serial.println("waiting..");
    nrf_err_check(9, sd_app_evt_wait());
}

void setup() {
  Serial.begin(115200); // TODO: well this seems to work!
  
  for (int i = 10; i >= 0; i--) {
    Serial.println(i, DEC);
    delay(1000);
  }
  advertiseBeacon();
}

void loop() {
}
