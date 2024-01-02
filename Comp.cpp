// #include "Comp.h"
// using namespace std;
// Comp::Comp(){
//     bankStorage1d.resize(100000);
//      sizev=0;
// }
// int Comp::hash(std::string id) {
//     // IMPLEMENT YOUR CODE HERE
// int max=131;
//   int j=0;
//    for(int i=0;i<id.length();i++){
//     int d=id[i]-'0';
//     j=(j*max+d)%100000;
//    }
//     return j; // Placeholder return value
// }
// int Comp::hash2(std::string id){
//   int hh=13;
//   int p=141;
//   for(int i=0;i<id.length();i++){
//     int d=id[i]-'0';
//     hh=(hh*37+d)%p;
//   }
//   return hh;

// }
// void Comp::createAccount(std::string id, int count) {
//     // IMPLEMENT YOUR CODE HERE
// int d=hash(id);
// int initial=d;
// int l=d;
// int top=hash2(id);

// while(bankStorage1d[d].id!=""){
    
//      d=(initial+top)%100000;
//      initial=initial+top;
//      if(d==l){
//         return;
//      }
// }

// Account kd;
// kd.id=id;
// kd.balance=count;

// bankStorage1d[d]=kd;
// sizev=sizev+1; 



// }

// std::vector<int> Comp::getTopK(int k) {
//     // IMPLEMENT YOUR CODE HERE
//     std::vector<int>vect1;
// //    std::vector<Account>vect;
  
//   for(int i=0;i<bankStorage1d.size();i++) {
//       if(bankStorage1d[i].id!=""){
//         vect1.push_back(bankStorage1d[i].balance);
          

//        }
//        }
//     int h=vect1.size();
//     sort2(vect1,0,h-1);
//     //  for (int g = 0; g < h; g++) {
//     //     std::cout << vect1[g] << " ";
//     // }
//     // std::cout << std::endl;
//     std::vector<int>vect2;
//   for(int g=0;g<k && g<h;g++){
//     vect2.push_back(vect1[g]);
//   }
   
     
    
//     return vect2;
//     // Placeholder return value
// }

// int Comp::getBalance(std::string id) {
//     // IMPLEMENT YOUR CODE HERE
//     int d=hash(id);
//     int l=d;
//     int initial=d;
//     int top=hash2(id);
//     int count=0;
//     if(id==bankStorage1d[d].id){
//         return bankStorage1d[d].balance;
//     }
    
//     while(bankStorage1d[d].id!=id){
        
//      d=(initial+top)%100003;
//      initial=initial+top;
//      count++;

//      if(count>=sizev || bankStorage1d[d].id==""){
//         return -1;
//      }
     
//     }
//     return bankStorage1d[d].balance; // Placeholder return value
// }


// void Comp::addTransaction(std::string id, int count) {
//     // IMPLEMENT YOUR CODE HERE
//     int d=hash(id);
//     int l=d;
//     int initial=d;
//     int top=hash2(id);
//     // if(bankStorage1d[d].id!=""){
        
//     //     bankStorage1d[d].balance=bankStorage1d[d].balance+count;
//     // }
//     // else{
//     while(bankStorage1d[d].id!=""){
//       if(id==bankStorage1d[d].id){
       
//          bankStorage1d[d].balance=bankStorage1d[d].balance+count;
//          return;
//     } 
//     d=(initial+top)%100000;
//      initial=initial+top;
//      if(d==l){
//         break;
//      }
//     }
   
//       createAccount(id,count);

//     }
    


// bool Comp::doesExist(std::string id) {
//     // IMPLEMENT YOUR CODE HERE
//     int d=hash(id);
//     int l=d;
//     int initial=d;
//     int top=hash2(id);
//     // if(id==bankStorage1d[d].id){
//     //     return true;
//     // }
//     // else{
//     while(bankStorage1d[d].id!=""){
//         if(id==bankStorage1d[d].id){
//         return true;
//      }
//      d=(initial+top)%100000;
//      initial=initial+top;
//      if(d==l){
//         break;
//      } 
//     }
    
//     //  else{
//          return false;
//     //  }
//     }
//      // Placeholder return value


// bool Comp::deleteAccount(std::string id) {
//     // IMPLEMENT YOUR CODE HERE
//     int d=hash(id);
//     int l=d;
//     int initial=d;
//     int top=hash2(id);
//     while(bankStorage1d[d].id!=""){
//     //     l=(d+(j*j))%100000;
//     //     j++;
//     // }
//     if(bankStorage1d[d].id==id){
        
//        bankStorage1d[d].id=""; 
//        bankStorage1d[d].balance=-1;
//     //    bankStorage1d.erase(bankStorage1d.begin()+d);
    
//        sizev=sizev-1;
//        return true;
//      }
//      d=(initial+top)%100000;
//      initial=initial+top;
//      if(d==l){
//         break;
//      } 
    
//      }
//     // }
//     return false;
//      // Placeholder return value
// }
// int Comp::databaseSize() {
//     // IMPLEMENT YOUR CODE HERE

//     return sizev; // Placeholder return value
// }

// // int Comp::hash(std::string id) {
// //     // IMPLEMENT YOUR CODE HERE
// //     return 0; // Placeholder return value
// // }
// int Comp::sort1(std::vector<int> &vect,int l,int e ){
   
//    int p = vect[l];
// 	int c = 0;
// 	for (int i = l + 1; i <= e; i++) {
// 		if (vect[i] >= p)
// 			c++;
// 	}
// 	int h = l + c;
//     int tmp=vect[h];
//             vect[h]=vect[l];
//             vect[l]=tmp;
// 	int i = l, j = e;

// 	while (i < h && j > h) {

// 		while (vect[i] >= p) {
// 			i++;
// 		}

// 		while (vect[j] < p) {
// 			j--;
// 		}

// 		if (i < h && j > h) {
// 			int temp=vect[i];
//             vect[i]=vect[j];
//             vect[j]=temp;
//             i++;
//             j--;
// 		}
// 	}

// 	return h;
//     }
// void Comp::sort2(std::vector<int> &vect,int l,int k ){
// if(l<k){
//     int h=sort1(vect,l,k);
//     sort2(vect,l,h-1);
//     sort2(vect,h+1,k);
// }
//    }
   
    
   
//     // Other data members and functions specific to Your implementation

// // Feel free to add any other helper functions you need
// // Good Luck!
// // int main()
// // {

// //     Comp new_chain;
// //     new_chain.createAccount("CDAD7786825_7990768648", 648);
// //     new_chain.createAccount("DCDA7547234_9919615552", 552);
// //     new_chain.createAccount("AACB1850545_7974534788", 788);

// //     // cout << new_chain.getBalance("CDAD7786825_7990768648")<<endl;
// //     cout << new_chain.databaseSize()<<endl;
// //      new_chain.createAccount("CDBD5250777_1124276711",711);
// //       new_chain.createAccount("ABCB8377155_0656808575",575);
// //       vector<int>vb=new_chain.getTopK(1);
// //       for(int i=0 ; i<vb.size() ; i++){
// //         cout<<vb[i]<<" ";
// //     }
// //     cout<<endl;
// // new_chain.createAccount("CDDC3792028_3313680038",38);
// // new_chain.createAccount("CBBA9574444_7470182321",321);
// // new_chain.createAccount("DBCC4334636_8057544188",188);
// // vector<int>vc=new_chain.getTopK(3);
// //   for(int i=0 ; i<vc.size() ; i++){
// //         cout<<vc[i]<<" ";
// //     }
// // new_chain.createAccount("BABD5741078_5109455304",304);
// // new_chain.createAccount("BCBA7529510_0817878868",868);
// //  cout << new_chain.databaseSize()<<endl;
// //  vector<int>vd=new_chain.getTopK(1);
// //    for(int i=0 ; i<vd.size() ; i++){
// //         cout<<vd[i]<<" ";
// //     }
// //  new_chain.addTransaction("BCBA7529510_0817878868",-860);
// //  cout << new_chain.getBalance("BCBA7529510_0817878868")<<endl;
// //   vector<int>ve=new_chain.getTopK(1);
// //     for(int i=0 ; i<ve.size() ; i++){
// //         cout<<ve[i]<<" ";
// //     }
// //    new_chain.addTransaction("DCDA7547234_9919615552",592);
// //    vector<int>vf=new_chain.getTopK(5);
// //   for(int i=0 ; i<vf.size() ; i++){
// //         cout<<vf[i]<<" ";
// //     }
// //     cout<<new_chain.deleteAccount("DCDA7547234_9919615552")<<endl;
// //     vector<int>vg=new_chain.getTopK(4);
// //       for(int i=0 ; i<vg.size() ; i++){
// //         cout<<vg[i]<<" ";
// //     }
// //     cout << new_chain.databaseSize()<<endl;
   

// //     return 0;
// // }
#include "Comp.h"
using namespace std;
Comp:: Comp(){

  bankStorage2d.resize(100000);
  // for(int i=0;i<bankStorage2d.size();i++){
  //  bankStorage2d[i][0].id="";
  //  bankStorage2d[i][0].balance=-1;
  // }
  sizev=0;

}
int Comp::hash(std::string id) {
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

void Comp::createAccount(std::string id, int count) {
    // IMPLEMENT YOUR CODE HERE
    int c=hash(id);
    Account user;
    user.id=id;
    user.balance=count;

   bankStorage2d[c].push_back(user);
   sizev=sizev+1;

}

std::vector<int> Comp::getTopK(int k) {
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

int Comp::getBalance(std::string id) {
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

void Comp::addTransaction(std::string id, int count) {
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

bool Comp::doesExist(std::string id) {
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


bool Comp::deleteAccount(std::string id) {

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
int Comp::databaseSize() {
    // IMPLEMENT YOUR CODE HERE

    return sizev; // Placeholder return value
}
int Comp::sort1(std::vector<int> &vect,int l,int e ){
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
void Comp::sort2(std::vector<int> &vect,int l,int k ){
if(l<k){
    int h=sort1(vect,l,k);
    sort2(vect,l,h-1);
    sort2(vect,h+1,k);
}
   
}

