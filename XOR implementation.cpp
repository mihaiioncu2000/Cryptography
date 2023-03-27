#include<iostream>
#include<string>
 using namespace std;
 
 int mod(int x, int y)
{
    int res = 0; 
     
    // 16  bit
    for (int i = 15; i >= 0; i--)                     
    {
       // bitii x y
       bool b1 = x & (1 << i);
       bool b2 = y & (1 << i);
        
       // Daca ambele sunt 1, atunci  xor este acelasi cu OR
        bool xoredBit = (b1 & b2) ? 0 : (b1 | b2);          
 
        // actualiz
        res <<= 1;
        res |= xoredBit;
    }
    return res;
}
 
 string criptare(string cheie,string m){
 	string result="";
 	
 	for(int i=0;i<m.length();i++){
 		result +=char(mod(int(m[i]-65+cheie[i]-65),26)+65); //transform fiecare caracter
	 }
 	
 	return result;
 }
 
 string decrypt(string cheie,string m){
 	string result="";
 	
 	for(int i=0;i<m.length();i++)
 	{
 		result+=char(mod(int((m[i]-65)-(cheie[i]-65)),26)+65);
	}
	
	return result;
 }
 
 int main(){
 	string m;
 	cout<<"Mesaj "<<'\n';
 	cin>>m;
 	string cheie;
 	cout<<"Introdu cheia"<<'\n';
 	cin>>cheie;
 	string cifru=criptare(cheie,m);
 	cout<<"Mesaj criptat: "<<cifru<<'\n';
 	cout<<"Mesaj decriptat: "<<decrypt(cheie,cifru)<<'\n';
 	
 	return 0;
 }
 
 
 
