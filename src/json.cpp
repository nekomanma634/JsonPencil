#include "./json.hpp"

Comms::Json::Json(){
    _result.append("{\n");
}

void Comms::Json::ClearJsonData(){
    _result = "{\n";
    _word = {};
}

void Comms::Json::Insert(std::string key, int value){
    std::string _key   = _doubleQuote + key + _doubleQuote;                 // jsonで文字列として扱うようダブルクォーテーションで囲む
    std::string _value = std::to_string(value);                             // 整数をstringに変換

    if(_word.size() != 0){                                                  // すでに単語があるならば,カンマを前の単語の先頭につける
        _word[_word.size()-1].insert(_word[_word.size()-1].size()-1,",");
        std::string s = _key + ": " + _value + "\n";                        // 今回の関数で受け取ったkeyとvalueを合わせて文字列化

        _word.push_back(s);
    }else{
        _word.push_back(_key + ": " + _value + "\n");
    }
}

void Comms::Json::Insert(std::string key, std::string value){               // Insert(string,int)型の方のオーバーロード (この関数は文字列型のみの場合の実装)
    std::string _key   = _doubleQuote + key   + _doubleQuote;
    std::string _value = _doubleQuote + value + _doubleQuote;

    if(_word.size() != 0){
        _word[_word.size()-1].insert(_word[_word.size()-1].size()-1,",");
        std::string s = _key + ": " + _value + "\n";

        _word.push_back(s);
    }else{
        _word.push_back(_key + ": " + _value + "\n");
    }
}

void Comms::Json::Update(){
    for(int i = 0; i < _word.size(); i++){
        _result.append(_word[i]);
    }

    _result.append("}");
}

std::string Comms::Json::GetJsonData(){
    return _result;
}