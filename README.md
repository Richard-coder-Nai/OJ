# OJ

my online judge CPP code 

## vimrc

```vimrc
autocmd FileType cpp map <F5> <ESC>:w<CR>:!g++ -std=c++11 % && ./a.out<CR>

set syntax=on
set nu
set showcmd
set tabstop=4
set softtabstop=4
set shiftwidth=4
set autoindent
set cindent
set noexpandtab
set smartindent 

inoremap ' ''<ESC>i
inoremap " ""<ESC>i
inoremap ( ()<ESC>i
inoremap [ []<ESC>i
inoremap { {}<ESC>i
```
