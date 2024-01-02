#include "CubicProbing.h"
using namespace std;
CubicProbing::CubicProbing(){
    bankStorage1d.resize(100000);
     sizev=0;
}
int CubicProbing::hash(std::string id) {
    // IMPLEMENT YOUR CODE HERE
   int max=1319;
   int j=0;
   for(int i=0;i<id.length();i++){
     int d=id[i]-'0';
     j=(j*max+d)%100001;
   }
   

    return j; // Placeholder return value
}
void CubicProbing::createAccount(std::string id, int count) {
    // IMPLEMENT YOUR CODE HERE
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
d=(initial+top*top*top)%100001;
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
    d=(hash(id)+top*top*top)%n;
    top++;
}
 
}
    
}



std::vector<int> CubicProbing::getTopK(int k) {
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

int CubicProbing::getBalance(std::string id) {
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
        
    
        l=(d+(j*j*j))%100001;
        j++;

        // if(l==d){
        //    return -1;
        // }
     
    
    }
    return bankStorage1d[l].balance;

 // Placeholder return value
}

void CubicProbing::addTransaction(std::string id, int count) {
    // IMPLEMENT YOUR CODE HERE
    int d=hash(id);
    long long l=d;
    long long j=1;
    if(!doesExist(id)){
         createAccount(id,count);
         return;
     }
    if(bankStorage1d[l].id==id){
       
         bankStorage1d[l].balance=bankStorage1d[l].balance+count;
         return;
     }
    while(bankStorage1d[d].id!=""|| bankStorage1d[d].balance==-1){
        d=(l+(j*j*j))%100001;
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
    createAccount(id,count);
    // else if(bankStorage1d[l].id.empty()){
    //   createAccount(id,count);
 
    // } 
    
}

bool CubicProbing::doesExist(std::string id) {
    // IMPLEMENT YOUR CODE HERE
    int d=hash(id);
    long long l=d;
   long long j=1;
    if(id==bankStorage1d[d].id){
        return true;
    }

    while(bankStorage1d[d].id!=""|| bankStorage1d[d].balance==-1){
        d=(l+(j*j*j))%100001;
        j++;
    if(id==bankStorage1d[d].id){
        return true;
     }
       
        if(d==l){
            return false;
        }
    }
    
     
    return false;
    
    // Placeholder return value
}

bool CubicProbing::deleteAccount(std::string id) {
    
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
    while(bankStorage1d[d].id!=""|| bankStorage1d[d].balance==-1){
     d=(l+j*j*j)%100001;
     j++;
     v++;
     if(bankStorage1d[d].id==id){
        
       bankStorage1d[d].id=""; 
       bankStorage1d[d].balance=-1;
    //    bankStorage1d.erase(bankStorage1d.begin()+d);
    
       sizev=sizev-1;
       return true;
     }
     if(d==l && v>=sizev){
        return false;
     }
     }
    // }
    return false;
    // Placeholder return value
}

int CubicProbing::databaseSize() {
    // IMPLEMENT YOUR CODE HERE
     return sizev;
    // Placeholder return value
}
int CubicProbing:: sort1(std::vector<int> &vect,int l,int e ){
    int p = vect[l];
	int c = 0;
	for (int i = l + 1; i <= e; i++) {
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
void CubicProbing:: sort2(std::vector<int> &vect,int l,int k ){
if(l<k){
    int h=sort1(vect,l,k);
    sort2(vect,l,h-1);
    sort2(vect,h+1,k);
}
   }
//    int main()
// {

//     CubicProbing new_chain;
//     new_chain.createAccount("CDAD7786825_7990768648", 648);
//     new_chain.createAccount("DCDA7547234_9919615552", 552);
//     new_chain.createAccount("AACB1850545_7974534788", 788);

//     // cout << new_chain.getBalance("CDAD7786825_7990768648")<<endl;
//     cout << new_chain.databaseSize()<<endl;
//      new_chain.createAccount("CDBD5250777_1124276711",711);
//       new_chain.createAccount("ABCB8377155_0656808575",575);
//       vector<int>vb=new_chain.getTopK(1);
//       for(int i=0 ; i<vb.size() ; i++){
//         cout<<vb[i]<<" ";
//     }
//     cout<<endl;
// new_chain.createAccount("CDDC3792028_3313680038",38);
// new_chain.createAccount("CBBA9574444_7470182321",321);
// new_chain.createAccount("DBCC4334636_8057544188",188);
// vector<int>vc=new_chain.getTopK(3);
//   for(int i=0 ; i<vc.size() ; i++){
//         cout<<vc[i]<<" ";
//     }
// new_chain.createAccount("BABD5741078_5109455304",304);
// new_chain.createAccount("BCBA7529510_0817878868",868);
//  cout << new_chain.databaseSize()<<endl;
//  vector<int>vd=new_chain.getTopK(1);
//    for(int i=0 ; i<vd.size() ; i++){
//         cout<<vd[i]<<" ";
//     }
//  new_chain.addTransaction("BCBA7529510_0817878868",-860);
//  cout << new_chain.getBalance("BCBA7529510_0817878868")<<endl;
//   vector<int>ve=new_chain.getTopK(1);
//     for(int i=0 ; i<ve.size() ; i++){
//         cout<<ve[i]<<" ";
//     }
//    new_chain.addTransaction("DCDA7547234_9919615552",592);
//    vector<int>vf=new_chain.getTopK(5);
//   for(int i=0 ; i<vf.size() ; i++){
//         cout<<vf[i]<<" ";
//     }
//     cout<<new_chain.deleteAccount("DCDA7547234_9919615552")<<endl;
//     vector<int>vg=new_chain.getTopK(4);
//       for(int i=0 ; i<vg.size() ; i++){
//         cout<<vg[i]<<" ";
//     }
//     cout << new_chain.databaseSize()<<endl;
   

//     return 0;
// }

