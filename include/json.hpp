#include <iostream>
#include <string>
#include <vector>
#include <map>

namespace Comms {
    
    class Json {
        private:
            struct Array{
                int                      mainWordIdx;
                std::vector<std::string> word;

                Array(int _mainWordIdx){
                    mainWordIdx  = _mainWordIdx;
                    word         = {};
                }
            };

            std::map<std::string, Array>               _array;
            std::vector<std::string>                   _word;
            std::string                                _result;
            const std::string                          _doubleQuote = R"(")";

        public:

            void ClearJsonData();                                         // データを削除
            void Update();                                                // josnデータの更新
            void Insert(std::string key, int value);                      // keyとintの内容
            void Insert(std::string key, std::string value);              // keyとstringの内容
            // void InsertArray(std::string variableName);                   // []のみの配列
            // void InsertArray(std::string name);                           // name:[]形式の配列
            std::string GetJsonData();                                    // 作成されたjsonデータを出力する
        
            Json();
    };
}