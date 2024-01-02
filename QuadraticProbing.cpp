
#include "QuadraticProbing.h"

using namespace std;
QuadraticProbing::QuadraticProbing(){
    bankStorage1d.resize(100000);
    sizev=0;
}
int QuadraticProbing::hash(std::string id) {
    // IMPLEMENT YOUR CODE HERE
  int max=1319;
  
   int j=0;
   for(int i=0;i<id.length();i++){
     int d=id[i]-'0';
      j=(j*max+d)%100001;
   }
  


    return j;// Placeholder return value
}

void QuadraticProbing::createAccount(std::string id, int count) {
    // IMPLEMENT YOUR CODE HERE
    // do rehashing
int d=hash(id);

long long initial=d;
long long top=1;
int m=100000;
// int attempt=99999;
while(m--){
if(bankStorage1d[d].id=="" || bankStorage1d[d].balance==-1){
     
   
    
Account kd;
kd.id=id;
kd.balance=count;
// bankStorage1d.insert(bankStorage1d.begin()+d,kd);
bankStorage1d[d]=kd;
sizev=sizev+1; 
return;
}
d=(initial+top*top)%100001;
top++;
if(d==initial){
    int n=bankStorage1d.size()*2;
    std::vector<Account>nw(n);
    for(int i=0;i<bankStorage1d.size();i++){
        if(bankStorage1d[d].id!="" || bankStorage1d[d].balance==-1){
            int k=hash(bankStorage1d[i].id)%n;
         while(nw[k].id!=""){
            k=(k+1)%n;
         }
         nw[k]=bankStorage1d[i];
        }
    }
    bankStorage1d=nw;
    d=(hash(id)+top*top)%n;
    top++;
}
 
}
}

std::vector<int> QuadraticProbing::getTopK(int k) {
    // IMPLEMENT YOUR CODE HERE
   std::vector<int>vect1;
//    std::vector<Account>vect;
  
  for(int i=0;i<bankStorage1d.size();i++) {
      if(bankStorage1d[i].id!=""){
        vect1.push_back(bankStorage1d[i].balance);
          

       }
       }
    int h=vect1.size();
    sort2(vect1,0,h-1);
    //  for (int g = 0; g < h; g++) {
    //     std::cout << vect1[g] << " ";
    // }
    // std::cout << std::endl;
    std::vector<int>vect2;
    if (k>h){
        k=h;
    }
  for(int g=0;g<k;g++){
    vect2.push_back(vect1[g]);
  }
   
     
    
    return vect2;
    // Placeholder return value

}

int QuadraticProbing::getBalance(std::string id) {
    // IMPLEMENT YOUR CODE HERE
    int d=hash(id);
    long long l=d;
    long long j=1;
    if(!doesExist(id)){
       return -1;
     }   
    if(bankStorage1d[l].id==id){
        return bankStorage1d[l].balance;
    }
    // if(id==bankStorage1d[d].id){
    //     return bankStorage1d[d].balance;
    // }
    // else{
    while(bankStorage1d[l].id!=id){
   
        l=(d+(j*j))%100001;
        j++;
      
     
    }
    return bankStorage1d[l].balance;
    
     // Placeholder return value
}

void QuadraticProbing::addTransaction(std::string id, int count) {
    // IMPLEMENT YOUR CODE HERE
   int d=hash(id);
 
    long long l=d;
     long long  j=1;
     if(!doesExist(id)){
         createAccount(id,count);
         return;
     }
     if(bankStorage1d[l].id==id){
       
         bankStorage1d[l].balance=bankStorage1d[l].balance+count;
         return;
     }
    // if(bankStorage1d[d].id!=""){

    //     bankStorage1d[d].balance=bankStorage1d[d].balance+count;
    // }
    
    while(bankStorage1d[d].id!="" || bankStorage1d[d].balance==-1){
         d=(l+(j*j))%100001;
         j++;
        
    if(bankStorage1d[d].id==id){
       
         bankStorage1d[d].balance=bankStorage1d[d].balance+count;
         return;
    }  
       
        
        if(d==l){

          createAccount(id,count);
          return;
            
        }
    }
   
    // createAccount(id,count);
    
} 
bool QuadraticProbing::doesExist(std::string id) {
    // IMPLEMENT YOUR CODE HERE
    int d=hash(id);
    long long l=d;
    long long  j=1;
    if(id==bankStorage1d[d].id){
        return true;
    }
    
    while(bankStorage1d[d].id!="" || bankStorage1d[d].balance==-1 ){
     d=(l+(j*j))%100001;
       j++; 
    if(id==bankStorage1d[d].id){
        return true;
     }
       

        if(d==l){
            break;
        }
    }
    return false;

    }
    // Placeholder return value


bool QuadraticProbing::deleteAccount(std::string id) {
    int d=hash(id);
    long long l=d;
    long long j=1;
    int v=0;
    if(!doesExist(id)){
           
        return false;
    }
    if(bankStorage1d[d].id==id){
       bankStorage1d[d].id=""; 
       bankStorage1d[d].balance=-1;
       sizev=sizev-1;
       return true;
     }
    
    while( bankStorage1d[d].id!="" || bankStorage1d[d].balance==-1 ){
  
     d=(l+(j*j))%100001;
     j++;
     v++;
     if(bankStorage1d[d].id==id){
       bankStorage1d[d].id=""; 
       bankStorage1d[d].balance=-1;
       sizev=sizev-1;
       return true;
     }
     
     
     if(d==l && v>=sizev){
        return false;
        
     }
     }
     return false;
    
     }
    
   


int QuadraticProbing::databaseSize() {
    // IMPLEMENT YOUR CODE HERE
    return sizev; // Placeholder return value
}

 int QuadraticProbing::sort1(std::vector<int> &vect,int l,int e){
    int p = vect[l];
	int c = 0;
	for (int i = l + 1; i <= e; i++){
		if (vect[i] >= p)
			c++;
	}
	int h = l + c;
    int tmp=vect[h];
            vect[h]=vect[l];
            vect[l]=tmp;
	int i = l, j = e;

	while (i < h && j > h) {

		while (vect[i] >= p) {
			i++;
		}

		while (vect[j] < p) {
			j--;
		}

		if (i < h && j > h) {
			int temp=vect[i];
            vect[i]=vect[j];
            vect[j]=temp;
            i++;
            j--;
		}
	}

	return h;
}
void QuadraticProbing::sort2(std::vector<int> &vect,int l,int k ){
if(l<k){
    int h=sort1(vect,l,k);
    sort2(vect,l,h-1);
    sort2(vect,h+1,k);
}
   }
