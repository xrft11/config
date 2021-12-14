-------------------------------
--  __________ 
-- < init.lua >
--  ---------- 
--    \
--     \
--        .--.
--       |o_o |
--       |:_/ |
--      //   \ \
--     (|     | )
--    /'\_   _/`\
--    \___)=(___/
--
-------------------------------

vim.o.wrap = false 
vim.o.mouse = 'a' 
vim.o.number = true 
vim.o.backup = false 
vim.o.swapfile = false 
vim.o.encoding = 'utf-8' 
vim.o.smartcase = true 
vim.o.incsearch = true 
vim.o.laststatus = 0 
vim.o.shiftwidth = 4 
vim.o.fileformat = 'unix' 
vim.o.smartindent = true 
vim.o.termguicolors = true 
vim.g.onedarkhc_terminal_italics = 1 

vim.cmd 'set guicursor=' 
vim.cmd 'colo onedarkhc' 
vim.cmd 'autocmd BufWritePost *bashrc !source %' 
vim.cmd 'autocmd BufWritePost *Xresources,*Xdefaults !xrdb %' 
