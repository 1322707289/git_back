#include<iostream>
#include<cstring>

using namespace std;

int main(int argc,char **argv){
	//判断命令的元素个数
	if(argc == 1){
		cout<<"Usage: run filename.cpp"<<endl;
	}else if(argc == 2){
		//获取参数信息
		string file_name(argv[1]);//通过char数组生成一个string对象
		size_t pos = file_name.find(".cpp");
		if(pos != file_name.npos){
		//find 找不到的时候会返回一个特殊的int值可以用npos标记

			//切割字符串
			string file = file_name.substr(0,pos);
			//通过系统调用来编译文件
			string cmd = "g++ -o "+file+" "+file_name;
			cout<<"编译中..."<<endl;
			system(cmd.c_str());
			cout<<"编译成功!"<<endl;
		}else{
			cout<<"Please input a C++ file"<<endl;
		}

	}
	return 0;
}
