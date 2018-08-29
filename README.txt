make
printf 'Hello world!\n' | openssl dgst -sha256
printf 'Hello world!\n' | ./a.out | xxd -p | { tr -d \\n ; echo ; }
