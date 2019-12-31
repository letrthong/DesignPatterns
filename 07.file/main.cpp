#include <fstream> 
#include <iostream> 
#include <map>
#include <bits/stdc++.h> 

using namespace std; 

#define  SIZE_MAX_WORD        1024

#define  VOCABULARY_MAX  10000
#define  SIZE_OF_HASH    28

#define  SIZE_OF_LEN     4

#define   POSITION_BODY_START     (VOCABULARY_MAX*SIZE_OF_HASH)


/****************************************************88*****
* define struct of header 
* len        index          value
* 4bytes     4 bytes        20bytes
*
**********************************************************/

 
 

class FileSystem{
  public:
     FileSystem(){
		loadMap();
	 }


	int hashArray(const std::string& key, bool& hasIndex ){
		hasIndex = false;
		int index = 0;
		for (std::map<int,std::string>::iterator it=_hashTable.begin(); it!=_hashTable.end(); ++it){
			std::cout << it->first << " => " << it->second << '\n';
			index =  it->first;
			if( key == std::string(it->second)){
				hasIndex = true;
				break;
			}
		}

		if(hasIndex ==false){
			index = index +1;
		}
		 
		return index ;
	}

	 
	 // include insert and update 
	 void insertKey(const std::string& key , const std::string& value){

		bool hasIndex = false;
		int index = hashArray(key, hasIndex);

	    if(true == hasIndex){
			std::cout << "Update  index= " << index <<endl;
			writefile( (POSITION_BODY_START + index*SIZE_MAX_WORD), value);
		}else{
			//Insert
			_hashTable[index ] = key;
			std::cout << "Insert  index= " << index <<endl;
			writefile( (POSITION_BODY_START + index*SIZE_MAX_WORD), value);
		}
	 }
	 
	 void deleteKey(const std::string& key) {
	 }
	 
	 
	 void searchKey(const std::string& key ,std::string& value){
		bool hasIndex = false;
		int index = hashArray(key, hasIndex);

	    if(true == hasIndex){
			readfile( (POSITION_BODY_START + index*SIZE_MAX_WORD), value);
			std::cout <<"index="<< index << " searchKey value=" << value <<endl;

		}else{
			 value = "";	 
		}
	 }
	 
	 
	 void readfile(int index, std::string& text){

		 bool existFile = hasFile("test.txt");
		fstream _myFile;

		if(existFile == true){
			 _myFile.open("test.txt",   ios::out | ios::in );
		}
		else{
			 _myFile.open("test.txt",   ios::out | ios::in | ios::trunc);
		}
		
		 char buffer[SIZE_MAX_WORD] ={}; 
		 if (_myFile.is_open() ){
			// _myFile.seekg(index,_myFile.beg);
			_myFile.flush();
			 _myFile.seekg(index, ios::beg);
			 _myFile.read(buffer, SIZE_MAX_WORD -1); 
		 }else{
			  std::cout << "read  Error open";
		 }
		

		text = std::string(buffer);

		 std::cout << "readfile  index =" << index  <<" buffer="<<buffer<<endl;

		 if(_myFile.is_open()){
			  _myFile.close(); 
		 }
	 }
	 
	 void writefile(int index, const std::string& text){
		bool existFile = hasFile("test.txt");
		fstream _myFile;

		if(existFile == true){
			 _myFile.open("test.txt",   ios::out | ios::in );
		}
		else{
			 _myFile.open("test.txt",   ios::out | ios::in | ios::trunc);
		}

		 std::cout << "writefile  index=" << index  <<" text="<<text <<" len="<< text.length()<<endl;
		 if(_myFile.is_open()){
			  _myFile.seekg(index );
		 	  _myFile.write (text.c_str(), text.length());  
		 }else{
			  std::cout << "write  Error open";
		 }

		 if(_myFile.is_open()){
			  _myFile.close(); 
		 }
		
	 }

	 std::string getHeader(){

		 bool existFile = hasFile("test.txt");
		fstream _myFile;

		if(existFile == true){
			 _myFile.open("test.txt",   ios::out | ios::in );
		}
		else{
			 _myFile.open("test.txt",   ios::out | ios::in | ios::trunc);
		}

		std::string  header ="";
		char buffer[POSITION_BODY_START] ={};  
		if (_myFile.is_open() ){
			if(_myFile.tellg() > 0){
				_myFile.seekg(0,ios::beg);
				_myFile.read(buffer, POSITION_BODY_START -1); 
			}

			
		 header = std::string(buffer);
			if(_myFile.is_open()){
				_myFile.close(); 
			}
		}
		return header;
	 }
	 
	 ~FileSystem(){
		 
	 }
	 
  private:

    bool hasFile(const std::string& path){
		bool ret =false;
		 if (FILE *file = fopen(path.c_str(), "r")) {
        	fclose(file);
			ret = true;
		 }
		return ret;
	}
	
	void loadMap(){
		int len;
		int index;
		std::string key;

		std::string temp;
		std::string  header = getHeader();

		for(int i = 0; i < header.length(); i++ ){
			temp = header.substr(0, SIZE_OF_LEN); 

			len = int2String(temp);
		}
	}

	int int2String(const std::string& number){
		int x = 0; 
		std::stringstream geek(number); 
    	geek >> x; 
		return x;
	}


	struct DataItem {
		char  len[SIZE_OF_LEN];
		char  index[4];
		char  key[20];
	};

	

	std::map<int, std::string> _hashTable;
};



int main (int argc, char** argv) { 

	FileSystem db;
	
	db.insertKey("123", "xyxyxyxyxyxy");
	db.insertKey("123", "xyxyxyxyxyxy");
	db.insertKey("abc", "1231111111111111111");

	std::string value = "";

	cout<<"\n search key"<<endl;
	db.searchKey("123", value);
	db.searchKey("abc", value);
	db.searchKey("123", value);
	return 0;
}  