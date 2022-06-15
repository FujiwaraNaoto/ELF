to install nasm
```
sudo apt install nasm
``

helloworld.c
helloworld.asm

to compile helloworld.asm, following commands must be input
```
nasm -f elf64 -o helloworld.o helloworld.asm
ld helloworld.o -o hello
```


確定していない
helloworld1.sの実行ファイルを作成する
nasm -f elf64 helloworld1.s
