#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <variant>
    
class Json {
    private:
        std::vector<std::string>                   _word;
        std::string                                _result;
        const std::string                          _doubleQuote = R"(")";

    public:

        void ClearJsonData();                                                                   // データを削除
        void Update();                                                                          // josnデータの更新
        void Insert(std::string key, int value);                                                // keyとintの内容
        void Insert(std::string key, std::string value);                                        // keyとstringの内容
        void InsertArray(std::string key, std::vector<std::variant<int,std::string>> value);    // 配列を追加する関数
        std::string GetJsonData();                                                              // 作成されたjsonデータを出力する
    
        Json();
};