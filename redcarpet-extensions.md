https://github.com/vmg/redcarpet/blob/master/README.markdown

https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet

http://jekyllrb.com/docs/configuration/#redcarpet

https://github.com/vmg/redcarpet/blob/master/README.markdown

The following extensions are accepted:

* `:no_intra_emphasis`: do not parse emphasis inside of words.
Strings such as `foo_bar_baz` will not generate `<em>` tags.

_foo_bar_baz_ vs foo_bar_baz

* `:tables`: parse tables, PHP-Markdown style.

| Tables        | Are           | Cool  |
| ------------- |:-------------:| -----:|
| col 3 is      | right-aligned | $1600 |
| col 2 is      | centered      |   $12 |
| zebra stripes | are neat      |    $1 |

* `:fenced_code_blocks`: parse fenced code blocks, PHP-Markdown
style. Blocks delimited with 3 or more `~` or backticks will be considered
as code, without the need to be indented. An optional language name may
be added at the end of the opening fence for the code block.

```javascript
var s = "JavaScript syntax highlighting";
alert(s);
```
 
```python
s = "Python syntax highlighting"
print s
```
 
```
No language indicated, so no syntax highlighting. 
But let's throw in a <b>tag</b>.
```

* `:autolink`: parse links even when they are not enclosed in `<>`
characters. Autolinks for the http, https and ftp protocols will be
automatically detected. Email addresses and http links without protocol,
but starting with `www` are also handled.

foo@bar.com
www.example.com
http://www.example.com/

* `:disable_indented_code_blocks`: do not parse usual markdown
code blocks. Markdown converts text with four spaces at
the front of each line to code blocks. This options
prevents it from doing so. Recommended to use
with `fenced_code_blocks: true`.

----
    var s = "JavaScript syntax highlighting";
    alert(s);
----

* `:strikethrough`: parse strikethrough, PHP-Markdown style.
Two `~` characters mark the start of a strikethrough,
e.g. `this is ~~good~~ bad`.

~~strikethrough~~

* `:lax_spacing`: HTML blocks do not require to be surrounded by an
empty line as in the Markdown standard.

surrounding non-empty line.
<table>
    <tr>
        <td>Foo</td>
    </tr>
</table>
surrounding non-empty line.

* `:space_after_headers`: A space is always required between the hash
at the beginning of a header and its name, e.g. `#this is my header`
would not be a valid header.

# This is a header

XYZ

#Is this also?

PQR

* `:superscript`: parse superscripts after the `^` character; contiguous superscripts
are nested together, and complex values can be enclosed in parenthesis, e.g.
`this is the 2^(nd) time`.

2^3^4 and 2^(a b c)^(x y z)

* `:underline`: parse underscored emphasis as underlines.
`This is _underlined_ but this is still *italic*`.

_underline_ and *italic*

* `:highlight`: parse highlights.
`This is ==highlighted==`. It looks like this: `<mark>highlighted</mark>`

==highlight==

* `:quote`: parse quotes.
`This is a "quote"`. It looks like this: `<q>quote</q>`

What is this one about?

* `:footnotes`: parse footnotes, PHP-Markdown style. A footnote works very much
like a reference-style link: it consists of a  marker next to the text (e.g.
`This is a sentence.[^1]`) and a footnote definition on its own line anywhere
within the document (e.g. `[^1]: This is a footnote.`).

Here is some text containing a footnote.[^somesamplefootnote]

[^somesamplefootnote]: Here is the text of the footnote itself.

Some more text.

# Jekyll special Redcarpet extensions

* `:no_fenced_code_blocks`: xyz.
Lorem...

* `:smart`: xyz.
Lorem...

"are these smart quotes" and ``these too'' and 'these also'?

An elipsis...

En and Em dashes a--b and x---y

Does it break where I put the breaks?

Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor
incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud
exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure
dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur.
Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit
anim id est laborum.
