-----------------------------------
--  __________
-- < init.lua >
--  ----------
--    \
--        .--.
--       |o_o |
--       |:_/ |
--      //   \ \
--     (|     | )
--    /'\_   _/`\
--    \___)=(___/
--
-----------------------------------

vim.o.ls = 0
vim.o.nu = true
vim.o.ru = false
vim.o.is = true
vim.o.si = true
vim.o.ff = 'unix'
vim.o.hls = false
vim.o.cul = true
vim.o.swf = false
vim.o.scs = true
vim.o.tgc = true
vim.o.wrap = false
vim.o.mouse = 'nicr'
vim.o.backup = false
vim.o.shiftwidth = 4
vim.g.onedarkhc_terminal_italics = 1

vim.cmd 'colo onedarkhc'
vim.cmd 'autocmd BufWritePost *bashrc !source %'
vim.cmd 'autocmd BufWritePost *Xresources,*Xdefaults !xrdb %'
