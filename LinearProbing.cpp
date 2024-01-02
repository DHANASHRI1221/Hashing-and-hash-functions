#include "LinearProbing.h"
// using namespace std;
LinearProbing::LinearProbing(){
    bankStorage1d.resize(100000);
    sizev=0;
}
int LinearProbing::hash(std::string id) {
    // IMPLEMENT YOUR CODE HERE
    
    int max=131;
 
   int j=0;
   for(int i=0;i<id.length();i++){
     int d=id[i]-'0';
      j=(j*max+d)%100000;
   }
  


    return j; // Placeholder return value
}


void LinearProbing::createAccount(std::string id, int count) {
    // IMPLEMENT YOUR CODE HERE
int d=hash(id);
int initial=d;
int top=1;
while(bankStorage1d[d].id!=""){
     d=(initial+top)%100000;
     top=top+1;
     if(d==initial){
        return;
     }
}
Account kd;
kd.id=id;
kd.balance=count;

bankStorage1d[d]=kd;
sizev=sizev+1;
}

std::vector<int> LinearProbing::getTopK(int k) {
    
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
   for(int g=0;g<k && g<h;g++){
    vect2.push_back(vect1[g]);
   }
   return vect2;
 // Placeholder return value
}

int LinearProbing::getBalance(std::string id) {
    // IMPLEMENT YOUR CODE HERE
   // IMPLEMENT YOUR CODE HERE
    // int d=hash(id);
    // int l=d;
    
    
    // // if(id==bankStorage1d[d].id){
    // //     return bankStorage1d[d].balance;
    // // }
    
    // while(bankStorage1d[d].id!=id){
    // //     d=(d+1)%100000;
    // //     if(bankStorage1d[d].id==""){
    // //         return -1;
    // //     }
    
    // // }
    // // return bankStorage1d[d].balance;
    // if(id==bankStorage1d[d].id){
    //     return bankStorage1d[d].balance;

    // }
    //  d=(d+1)%100001;
    //  if(d==l){
    //     break;
    //  }

    // }
    // return -1;
    // int d=hash(id);
    // int l=d;
    // long long j=1;
    // int m=0;
    // // if(id==bankStorage1d[d].id){
    // //     return bankStorage1d[d].balance;
    // // }
    // // else{
    // while(bankStorage1d[l].id!=id){
        
    
    //     l=(d+(j))%100001;
    //     j++;
    //  if(bankStorage1d[l].id!=""){
    //     m++;
    //  }   
    //  if(m>sizev || j>=75000){
    //    return -1;
    //  }
    // }
    // return bankStorage1d[l].balance;
    // Placeholder return value
    int d=hash(id);
    int l=d;
    int count=0;
    
    // if(id==bankStorage1d[d].id){
    //     return bankStorage1d[d].balance;
    // }
    
    while(bankStorage1d[d].id!=id){
    //     d=(d+1)%100000;
    //     if(bankStorage1d[d].id==""){
    //         return -1;
    //     }
     d=(d+1)%100001;
    // }
    // return bankStorage1d[d].balance;
    if(bankStorage1d[d].id!="0"){
        count++;
       

    }
     
     if(count>=sizev || bankStorage1d[d].id==""){
       return -1;
     }

}
        return bankStorage1d[d].balance;
}


void LinearProbing::addTransaction(std::string id, int count) {
    // IMPLEMENT YOUR CODE HERE
   
    int d=hash(id);
    int l=d;
    // if(id==bankStorage1d[d].id){
         
    //     bankStorage1d[d].balance=bankStorage1d[d].balance+count;
    // }
    // else{
    while( bankStorage1d[d].id!="" ){
        
        // d=(d+1)%100000;
        // if(d==l){
        //     createAccount(id,count);
        //     return;
        // }
        if(bankStorage1d[d].id==id){
    
         bankStorage1d[d].balance=bankStorage1d[d].balance+count;
         return;
    }
     d=(d+1)%100000;
     if(d==l){
        break;
     }    
    }
    // if(bankStorage1d[d].id==id){
    
    //      bankStorage1d[d].balance=bankStorage1d[d].balance+count;
    // }
    // else {
       
       createAccount(id,count);
      
    // }
    }



bool LinearProbing::doesExist(std::string id) {
    // IMPLEMENT YOUR CODE HERE
    int d=hash(id);
    int l=d;
    
    if(id==bankStorage1d[d].id){
        return true;
    }
    
    while(bankStorage1d[l].id !=""){
       
        if(id==bankStorage1d[l].id){
            return true;
        }
      l=(l+1)%100000;
     if(l==d){
        break;
     }
    
    }
    

        return false;
    
    
       
    
    
    
     // Placeholder return value
}

bool LinearProbing::deleteAccount(std::string id) {
    // IMPLEMENT YOUR CODE HERE
    int d=hash(id);
    int l=d;
    // if(id==bankStorage1d[d].id){
    //    bankStorage1d.erase(bankStorage1d.begin()+d);
    //    sizev=sizev-1; 
    //    return true;
    // }
    
    while( bankStorage1d[d].id!=""){
    //     d=(d+1)%100000;
    //  if(d==l){
    //     return false;
    //  }
    
    
    if(id==bankStorage1d[d].id){
       bankStorage1d[d].id="";
       bankStorage1d[d].balance=-1;
     
    //  bankStorage1d[d]=Account();
       sizev=sizev-1;
       return true;
    }
    d=(d+1)%100000;
    if(d==l){
        break;
    }

    }
    
    return false;
    
    

   // Placeholder return value

}
int LinearProbing::databaseSize() {
    // IMPLEMENT YOUR CODE HERE
    return sizev; // Placeholder return value
}
int LinearProbing::sort1(std::vector<int> &vect,int l,int e ){
//     int p=vect[k];
//     int y= l-1;
//     for(int m=l;m<k;m++){
//         if(vect[m]>=p){
//            y++;
//            int c=vect[y];
//            vect[y]=vect[m];
//            vect[m]=c;
//         //    int c=a;
//         //    a=b;
//         //    b=c;
//         }
//         }
//         int x=vect[y+1];
//          vect[y+1] =vect[k];
//          vect[k]=x;
//         //    int f=d;
//         //    d=e;
//         //    e=f;
//   return (y+1);
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
void LinearProbing::sort2(std::vector<int> &vect,int l,int k ){
if(l<k){
    int h=sort1(vect,l,k);
    sort2(vect,l,h-1);
    sort2(vect,h+1,k);
}
   }










