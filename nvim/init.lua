-----------------------------------
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
-----------------------------------

vim.o.hls = false
vim.o.wrap = false
vim.g.t_Co = 256
vim.o.mouse = 'a'
vim.o.ruler = false
vim.o.mouse = 'nicr'
vim.o.number = true
vim.o.backup = false
vim.o.tabstop = 4
vim.o.swapfile = false
vim.o.encoding = 'UTF-8'
vim.o.wildmenu = true
vim.o.smarttab = true
vim.o.smartcase = true
vim.o.incsearch = true
vim.o.cmdheight = 1
vim.o.expandtab = true
vim.o.laststatus = 0
vim.o.shiftwidth = 4
vim.o.fileformat = 'unix'
vim.o.smartindent = true
vim.o.termguicolors = true
vim.g.onedarkhc_terminal_italics = 1

vim.cmd 'colo onedarkhc'
vim.cmd 'autocmd BufWritePost *bashrc !source %'
vim.cmd 'autocmd BufWritePost *Xresources,*Xdefaults !xrdb %'
