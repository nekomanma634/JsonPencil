#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <variant>
    
class Json {
    private:
        using JsonTypes = std::variant<int, bool, double, std::string>;

        std::vector<std::string> _word;
        std::string              _result;
        const std::string        _doubleQuote = R"(")";

        //

    public:
        void ClearJsonData();                                            // データを削除
        void Update();                                                   // josnデータの更新
        void Insert(std::string key, JsonTypes value);                   // keyとintの内容
        void InsertArray(std::string key, std::vector<JsonTypes> value); // 配列を追加する関数
        std::string MakeArray(std::vector<JsonTypes> value);             // [1,2,"mican"]のような形の文字列を作成する
        std::string GetJsonData();                                       // 作成されたjsonデータを出力する
    
        Json();
};