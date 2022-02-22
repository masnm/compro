if &cp | set nocp | endif
nnoremap ,rs ?usingj:-1read $HOME/codes/habijabi/Snippets/read_string.cpp2jf[a
nnoremap ,ycn G7kvld?solve
nnoremap ,ncn G7ki//?solve
nnoremap ,ytc G9kvld?solve
nnoremap ,ntc G9ki//?solve
nnoremap ,java :-1read $HOME/codes/habijabi/Snippets/main.java8ggf{hi
nnoremap ,cpp :-1read $HOME/codes/habijabi/Snippets/main.cpp38ggzt
nnoremap ,cc :-1read $HOME/codes/habijabi/Snippets/main.c4ggo
let s:cpo_save=&cpo
set cpo&vim
vmap gx <Plug>NetrwBrowseXVis
nmap gx <Plug>NetrwBrowseX
vnoremap <silent> <Plug>NetrwBrowseXVis :call netrw#BrowseXVis()
nnoremap <silent> <Plug>NetrwBrowseX :call netrw#BrowseX(netrw#GX(),netrw#CheckIfRemote(netrw#GX()))
noremap <Right> <Nop>
noremap <Left> <Nop>
noremap <Down> <Nop>
noremap <Up> <Nop>
let &cpo=s:cpo_save
unlet s:cpo_save
set background=dark
set backspace=indent,eol,start
set dictionary=/usr/share/dict/american-english
set fileencodings=ucs-bom,utf-8,default,latin1
set helplang=en
set listchars=tab:·\ ,
set makeprg=my_code_compile_cmnd.sh\ %
set path=.,/usr/include,,,**,/usr/include/c++/11/
set printoptions=paper:letter
set ruler
set runtimepath=~/.vim,~/.vim/plugged/vim-cpp-enhanced-highlight,~/.vim/plugged/dracula,/var/lib/vim/addons,/etc/vim,/usr/share/vim/vimfiles,/usr/share/vim/vim82,/usr/share/vim/vimfiles/after,/etc/vim/after,/var/lib/vim/addons/after,~/.vim/plugged/vim-cpp-enhanced-highlight/after,~/.vim/plugged/dracula/after,~/.vim/after
set shiftwidth=4
set suffixes=.bak,~,.swp,.o,.info,.aux,.log,.dvi,.bbl,.blg,.brf,.cb,.ind,.idx,.ilg,.inx,.out,.toc
set tabstop=4
set wildmenu
" vim: set ft=vim :
