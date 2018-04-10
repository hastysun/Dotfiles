""""""""""""""""""""""""""""""""""""""">
""""""""""""""""""""""""""""""""""""""">
" >> HastyVim
"
" >> April 2018
"
" >> Version 1.1
"
""""""""""""""""""""""""""""""""""""""">
""""""""""""""""""""'"""""""""""""""""">
"         ________ ++     ________
"       /VVVVVVVV\++++  /VVVVVVVV\
"       \VVVVVVVV/++++++\VVVVVVVV/
"        |VVVVVV|++++++++/VVVVV/'
"        |VVVVVV|++++++/VVVVV/'
"       +|VVVVVV|++++/VVVVV/'+
"     +++|VVVVVV|++/VVVVV/'+++++
"   +++++|VVVVVV|/VVV___++++++++++
"     +++|VVVVVVVVVV/##/ +_+_+_+_
"       +|VVVVVVVVV___ +/#_#,#_#,\
"        |VVVVVVV//##/+/#/+/#/'/#/
"        |VVVVV/'+/#/+/#/+/#/ /#/
"        |VVV/'++/#/+/#/ /#/ /#/
"        'V/'  /##//##//##//###/
"                ++
""""""""""""""""""""""""""""""""""""""">
""""""""""""""""""""""""""""""""""""""">


""""""""""""""""""""""""""""""""""""""">
"" -=> General <=-
""""""""""""""""""""""""""""""""""""""">

filetype indent on

set paste

set nocompatible  

set noswapfile

set ttyfast

set autoindent

set tabstop=4


""""""""""""""""""""""""""""""""""""""">
"" -=> Appearance <=- 
""""""""""""""""""""""""""""""""""""""">

set ruler

syntax on


""""""""""""""""""""""""""""""""""""""">
"" -=> Keybindings <=-
""""""""""""""""""""""""""""""""""""""">
map ; :

map <silent> <F2> :set number <CR>
map <silent> <F2> :set number! <CR>

map <silent> <F3> :set relativenumber <CR>

map <silent> <F4> :set cursorline <CR>
map <silent> <F4> :set cursorline! <CR>

map <silent> <F5> :setlocal spell! spelllang=en_us <CR>

map <silent> <F6> :IndentGuidesToggle <CR>

" map <silent> <F6> :Goyo <CR>


""""""""""""""""""""""""""""""""""""""">
"" -=> Plugins <=- 
""""""""""""""""""""""""""""""""""""""">

"""""""""""""""""""""""""""""""">
call plug#begin('~/.vim/plugged')
"""""""""""""""""""""""""""""""">

" Indent Guides
" Plug 'nathanaelkane/vim-indent-guides'

" Jedi
" Plug 'davidhalter/jedi-vim'

" Deliminate
" Plug 'raimondi/delimitmate'

" Supertab
" Plug 'ervandew/supertab'

" Surround
" Plug 'tpope/vim-surround'

" Tabular
" Plug 'godlygeek/tabular'

" Syntastic
" Plug 'scrooloose/syntastic'

" Goyo "
" Plug 'junegunn/goyo.vim'

" Nerd Tree "
" Plug 'scrooloose/nerdtree'

" Auto Pairs "
" Plug 'jiangmiao/auto-pairs'


""""""""""""""""""""""""""""""""">
call plug#end()
""""""""""""""""""""""""""""""""">


""""""""""""""""""""""""""""""""""""""">
"" -=> Misc <=-
""""""""""""""""""""""""""""""""""""""">
