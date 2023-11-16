set tabstop=8 shiftwidth=8
set autoindent
set smartindent
set cindent
syntax enable
set number
set ff=unix
set formatoptions+=r
set fileformat=unix
set fileformats=unix
set hlsearch
set incsearch
set nobackup
set bs=2
set omnifunc=syntaxcomplete#Complete
set nocompatible
set wildmode=list,full,longest
set ff=unix
set formatoptions+=r
set fileformat=unix
set fileformats=unix
set ruler
colo darkblue

inoremap " ""<left>
inoremap ' ''<left>
inoremap ( ()<left>
inoremap [ []<left>
inoremap { {}<left>
inoremap {<CR> {<CR>}<ESC>O
inoremap {;<CR> {<CR>};<ESC>O

highlight CursorLine guibg=#303030

syntax on
