# mRsa
A base rsa to generate active key by the computer's MacAddress

## How it works ?
- 1. First,the software will get you pc's macaddress,and encryption the
madaddress by base64. After this,we get the string U.We sum the value of 
U's each word,and we get the mac value M.

- 2. User send the U to the developer . Developer get the sum of U's words
value S.Then Generate a public_key ,encode_key and decode_key. Encryption 
S bythe publick and encode_key,and get the value D.

- 3. Send the decode_key and publick_key and value D to the software user.User input the 
decode_key and public and D,the decryption ,get a value T.

- 4. Compare  T and M.If T eaual M,the active the software.
