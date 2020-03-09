" This tests to see if vim was configured with the '--enable-cscope' option
" when it was compiled.  If it wasn't, time to recompile vim...
if has("cscope")

	""""""""""""" Standard cscope/vim boilerplate
	" use both cscope and ctag for 'ctrl-]', ':ta', and 'vim -t'
	set cscopetag

	" check cscope for definition of a symbol before checking ctags: set to 1
	" if you want the reverse search order.
	set csto=0

	" add any cscope database in current directory
	if filereadable("cscope.out")
		cs add cscope.out
	" else add the database pointed to by environment variable
	elseif $CSCOPE_DB != ""
		cs add $CSCOPE_DB
	endif

	" show msg when any other cscope db added
	set cscopeverbose

	"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
	"                   My cscope/vim key mappings
	"
	" The following maps all invoke one of the following cscope search types:
	"
	"   's'   symbol: find all references to the token under cursor
	"   'g'   global: find global definition(s) of the token under cursor
	"   'c'   calls:  find all calls to the function name under cursor
	"   't'   text:   find all instances of the text under cursor
	"   'e'   egrep:  egrep search for the word under cursor
	"   'f'   file:   open the filename under cursor
	"   'i'   includes: find files that include the filename under cursor
	"   'd'   called: find functions that function under cursor calls
	"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
	nmap <C-\>s :cs find s <C-R>=expand("<cword>")<CR><CR>
	nmap <C-\>g :cs find g <C-R>=expand("<cword>")<CR><CR>
	nmap <C-\>c :cs find c <C-R>=expand("<cword>")<CR><CR>
	nmap <C-\>t :cs find t <C-R>=expand("<cword>")<CR><CR>
	nmap <C-\>e :cs find e <C-R>=expand("<cword>")<CR><CR>
	nmap <C-\>f :cs find f <C-R>=expand("<cfile>")<CR><CR>
	nmap <C-\>i :cs find i <C-R>=expand("<cfile>")<CR><CR>
	nmap <C-\>d :cs find d <C-R>=expand("<cword>")<CR><CR>

	" If you are lazy to type entire cscope commands, below shoctcuts are the
	" way to go.
	nmap ss :cs find s <C-R>=expand("<cword>")<CR><CR>
	nmap gg :cs find g <C-R>=expand("<cword>")<CR><CR>
	nmap cc :cs find c <C-R>=expand("<cword>")<CR><CR>
	nmap tt :cs find t <C-R>=expand("<cword>")<CR><CR>

endif
