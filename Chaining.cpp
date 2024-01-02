#include "Chaining.h"
using namespace std;
Chaining:: Chaining(){

  bankStorage2d.resize(100000);
  // for(int i=0;i<bankStorage2d.size();i++){
  //  bankStorage2d[i][0].id="";
  //  bankStorage2d[i][0].balance=-1;
  // }
  sizev=0;

}
int Chaining::hash(std::string id) {
    // IMPLEMENT YOUR CODE HERE
    // int hash=0;
  //  int p=37;
  //  int q=41;
  //  int h= 171;
  //  int g= 97;
  int max=131;
  
   int j=0;
   for(int i=0;i<id.length();i++){
     int d=id[i]-'0';
      j=(j*max+d)%100000;
   }
  


    return j; // Placeholder return value
}

void Chaining::createAccount(std::string id, int count) {
    // IMPLEMENT YOUR CODE HERE
    int c=hash(id);
    Account user;
    user.id=id;
    user.balance=count;

   bankStorage2d[c].push_back(user);
   sizev=sizev+1;

}

std::vector<int> Chaining::getTopK(int k) {
    // IMPLEMENT YOUR CODE HERE
  //  std::vector<int>vect1;
  //  std::vector<Account>vect;
  int  i=0;
 vector<int>vect1;
    while(i<bankStorage2d.size()){
       for(int j=0;j<bankStorage2d[i].size();j++){
        if(bankStorage2d[i][j].id!=""){
          vect1.push_back(bankStorage2d[i][j].balance);
        }

       }
      i++;
    }

    int h=vect1.size();
    sort2(vect1,0,h-1);
    //  for (int g = 0; g < h; g++) {
    //     std::cout << vect1[g] << " ";
    // }
    // std::cout << std::endl;
    std::vector<int>vect2;
    
  for(int g=0;g<k && g<h;g++){
    vect2.push_back(vect1[g]);
  }
   
     
    
    return vect2; // Placeholder return value
}

int Chaining::getBalance(std::string id) {
    // IMPLEMENT YOUR CODE HERE
   int c=hash(id);
    // Account user;
    // user.id=id;
  std::vector<Account>vect;
  vect = bankStorage2d[c];
  // int d=-1;
  int i=0;
 while(i<vect.size()){
    if(vect[i].id==id){
      return vect[i].balance;

    }
    i++;
    }
  // if(d!=0){
  //   return d;
  // }  
  // else{
  //   return -1;
  // }
  return -1;
   
    

    // Placeholder return value
}

void Chaining::addTransaction(std::string id, int count) {
    // IMPLEMENT YOUR CODE HERE
    int c=hash(id);
    std::vector<Account>&vect = bankStorage2d[c];
    bool z=false;
  
    for(int i=0;i<vect.size();i++){
       if(vect[i].id==id){
          vect[i].balance= vect[i].balance+(count);
          z=true;
          break;
          
       }
    }
       if(!z){
        
        createAccount(id,count);
       }
       
    


}

bool Chaining::doesExist(std::string id) {
    // IMPLEMENT YOUR CODE HERE
    int c=hash(id);
    std::vector<Account>vect;
    vect = bankStorage2d[c];
    bool exists=false;
  for(int i=0;i<vect.size();i++){
    if(vect[i].id==id){
      exists=true;

    }
    }
    return exists;

 
}


bool Chaining::deleteAccount(std::string id) {

    // IMPLEMENT YOUR CODE HERE
    int c=hash(id);
    // std::vector<Account>vect;
    // vect = bankStorage2d[c];
    std::vector<Account> &vect = bankStorage2d[c];
    bool res=false;
  
    for(int i=0;i<vect.size();i++){
        if(vect[i].id==id) {
            vect[i].id="";
            vect[i].balance=-1;
            res=true;
            sizev=sizev-1;
            
        }

    }
    return res; // Placeholder return value
}
int Chaining::databaseSize() {
    // IMPLEMENT YOUR CODE HERE

    return sizev; // Placeholder return value
}
int Chaining::sort1(std::vector<int> &vect,int l,int e ){
  //   int p=vect[k];
  //   int y= l-1;
  //   for(int m=l;m<k;m++){
  //       if(vect[m]>=p){
  //          y++;
  //          int c=vect[y];
  //          vect[y]=vect[m];
  //          vect[m]=c;
  //       //    int c=a;
  //       //    a=b;
  //       //    b=c;
  //       }
  //       }
  //       int x=vect[y+1];
  //        vect[y+1] =vect[k];
  //        vect[k]=x;
  //       //    int f=d;
  //       //    d=e;
  //       //    e=f;
  // return (y+1);
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
void Chaining::sort2(std::vector<int> &vect,int l,int k ){
if(l<k){
    int h=sort1(vect,l,k);
    sort2(vect,l,h-1);
    sort2(vect,h+1,k);
}
   
}

