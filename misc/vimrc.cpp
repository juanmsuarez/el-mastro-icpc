colo desert
set number 
set norelativenumber
set autochdir
set colorcolumn=80
set ignorecase
set showcmd
augroup cpp
    autocmd!
    autocmd FileType cpp map <f9> :w<enter> :!g++ -std=c++14 -W -Wall -Wshadow -Wconversion -DLOCAL -D_GLIBCXX_DEBUG -g3 "%" -o "a" <enter>
    autocmd FileType cpp map <f5> :!"./a" < a.in <enter> 
    autocmd FileType cpp map <f6> :!"./a" <enter>
augroup END 
set tabstop=4
set shiftwidth=4
set softtabstop=4
set expandtab
set smartindent
set cindent
set clipboard=unnamedplus
nmap <c-h> <c-w><c-h>
nmap <c-j> <c-w><c-j>
nmap <c-k> <c-w><c-k>
nmap <c-l> <c-w><c-l>
vmap > >gv
vmap < <gv
map j gj
map k gk
nnoremap <silent> [b :bp<CR>
nnoremap <silent> ]b :bn<CR>
nnoremap <silent> [B :bf<CR>
nnoremap <silent> ]B :bl<CR>
set splitright
set nobackup
set nowritebackup
set noswapfile
