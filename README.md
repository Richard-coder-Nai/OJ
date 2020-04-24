# OJ

back up part of my OJ CPP code.

## vimrc

```vimrc
autocmd FileType cpp map <F5> <ESC>:w<CR>:!g++ -std=c++11 % && ./a.out<CR>
autocmd BufNewFile,BufReadPre *.java nmap <F5> <ESC>:w<CR>:!javac %<cr>:!java %:r<cr>

imap jj <esc>
imap kk <esc>
imap jk <esc>
imap kj <esc>

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
set hlsearch 

inoremap ' ''<ESC>i
inoremap " ""<ESC>i
inoremap ( ()<ESC>i
inoremap [ []<ESC>i
inoremap { {}<ESC>i
```
