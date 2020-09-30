#include <iostream>

using namespace std;

/*移位变换加密算法*/
string Cryption(string text, int move){
    char small_letters[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char big_letters[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int pos=0;  // 字母在数组的位置，从0开始算
    int len = text.length();  // 字符串的长度
    for(int i=0; i<len; i++){
        if(text[i]>='a' && text[i]<='z'){
            for(int j=0; j<26; j++){
                if(small_letters[j]==text[i]){
                    pos = j;
                }
            }
            text[i] = (pos+move)%26 + 'a';
        }
        if(text[i]>='A' && text[i]<='Z'){
            for(int j=0; j<26; j++){
                if(big_letters[j]==text[i]){
                    pos = j;
                }
            }
            text[i] = (pos+move)%26 + 'A';
        }
    }
    text[len] = '\0';
    return text;
}

/*移位变换解密算法*/
string Decryption(string text, int move){
    char small_letters[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char big_letters[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int pos=0;
    int len = text.length();
    for(int i=0; i<len; i++){
        if(text[i]>='a' && text[i]<='z'){
            for(int j=0; j<26; j++){
                if(small_letters[j]==text[i]){
                    pos = j;
                }
            }
            text[i] = (pos-move+26)%26 + 'a';
        }
        if(text[i]>='A' && text[i]<='Z'){
            for(int j=0; j<26; j++){
                if(big_letters[j]==text[i]){
                    pos = j;
                }
            }
            text[i] = (pos-move+26)%26 + 'A';
        }
    }
    text[len] = '\0';
    return text;
}

int main()
{
    string text;
    int move;
    int choice;
    cout<<"移动几位？"<<endl;
    cin>>move;
    cout<<"加密(0) or 解密(1) ？ 请输入数字: ";
    cin>>choice;
    if(choice==0){
        //加密
        cout<<"输入明文字符串："<<endl;
        cin>>text;
        cout<<"密文：\n"<<Cryption(text, move)<<endl;
    }
    else if(choice==1){
        //解密
        cout<<"请输入密文字符串："<<endl;
        cin>>text;
        cout<<"明文：\n"<<Decryption(text, move)<<endl;
    }
    else{
        cout<<"Something wrong!"<<endl;
    }
    return 0;
}
