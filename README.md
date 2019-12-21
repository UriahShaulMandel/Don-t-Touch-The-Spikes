# Don't Touch The Spikes! ![GitHub top language](https://img.shields.io/github/languages/top/UriahShaulMandel/Don-t-Touch-The-Spikes)
Assembly x86 game I developed 2 years ago for a school project (was 15 years old)

![gif](https://github.com/UriahShaulMandel/Don-t-Touch-The-Spikes/blob/master/gif.gif?raw=true)

Haven't touched the code since. 
Here is one cool thing I remember I did:
``` assembly
drawNumber proc number:dword,x:dword,y:dword
  pusha
  xor edx,edx
  mov eax,number
  mov ebx,10
  div ebx
  mov ecx,eax
  cmp eax,0
  jne yes
  no:
  invoke drawDigit,number,x,y
  add x,LETTER_WIDTH
  popa
  mov eax,x
  ret
  yes:
  invoke drawNumber,ecx,x,y
  invoke drawDigit,edx,eax,y
  add x,LETTER_WIDTH
  popa
  mov eax,x
  ret
drawNumber endp
```
Check it out [here](https://github.com/UriahShaulMandel/Don-t-Touch-The-Spikes/blob/edb22396f14bc1d9792b05f7b2dac9ecc711f3d4/Final/funcs.inc#L53-L75)

The project is built the following way:
 - [main funcs](https://github.com/UriahShaulMandel/Don-t-Touch-The-Spikes/blob/master/Final/main_funcs.inc) - The main functions, [draw](https://github.com/UriahShaulMandel/Don-t-Touch-The-Spikes/blob/edb22396f14bc1d9792b05f7b2dac9ecc711f3d4/Final/main_funcs.inc#L12-L21), [update](https://github.com/UriahShaulMandel/Don-t-Touch-The-Spikes/blob/edb22396f14bc1d9792b05f7b2dac9ecc711f3d4/Final/main_funcs.inc#L23-L28) and [init](https://github.com/UriahShaulMandel/Don-t-Touch-The-Spikes/blob/edb22396f14bc1d9792b05f7b2dac9ecc711f3d4/Final/main_funcs.inc#L4-L10)
 - [funcs](https://github.com/UriahShaulMandel/Don-t-Touch-The-Spikes/blob/master/Final/funcs.inc) functions used
 - [smallys](https://github.com/UriahShaulMandel/Don-t-Touch-The-Spikes/blob/master/Final/smallys.inc) small helper functions
 - [data](https://github.com/UriahShaulMandel/Don-t-Touch-The-Spikes/blob/master/Final/data.inc) the variables
 - [dataBASE](https://github.com/UriahShaulMandel/Don-t-Touch-The-Spikes/blob/master/Final/dataBASE.inc) - where I kept all the long constants
 - [structs](https://github.com/UriahShaulMandel/Don-t-Touch-The-Spikes/blob/master/Final/structs.inc)
 - [constants](https://github.com/UriahShaulMandel/Don-t-Touch-The-Spikes/blob/master/Final/constants.inc)
 - [Source](https://github.com/UriahShaulMandel/Don-t-Touch-The-Spikes/blob/master/Final/Source.asm) The main function
