#include "./json.hpp"

Json::Json(){
    _result.append("{\n");
}

void Json::ClearJsonData(){
    _result = "{\n";
    _word = {};
}

void Json::Insert(std::string key, std::variant<int,std::string> value){
    std::string _key   = _doubleQuote + key + _doubleQuote;                 // jsonで文字列として扱うようダブルクォーテーションで囲む
    std::string _value;

    if(int* pValue = std::get_if<int>(&value)){
        _value = std::to_string(*pValue);

    }else if(std::string* pValue = std::get_if<std::string>(&value)){
        _value = _doubleQuote + *pValue + _doubleQuote;
        
    }

    if(_word.size() != 0){                                                  // すでに単語があるならば,カンマを前の単語の先頭につける
        _word[_word.size()-1].insert(_word[_word.size()-1].size()-1,",");
        std::string s = _key + ": " + _value + "\n";                        // 今回の関数で受け取ったkeyとvalueを合わせて文字列化

        _word.push_back(s);
    }else{
        _word.push_back(_key + ": " + _value + "\n");
    }
}

// void Json::Insert(std::string key, std::string value){               // Insert(string,int)型の方のオーバーロード (この関数は文字列型のみの場合の実装)
//     std::string _key   = _doubleQuote + key   + _doubleQuote;
//     std::string _value = _doubleQuote + value + _doubleQuote;

//     if(_word.size() != 0){
//         _word[_word.size()-1].insert(_word[_word.size()-1].size()-1,",");
//         std::string s = _key + ": " + _value + "\n";

//         _word.push_back(s);
//     }else{
//         _word.push_back(_key + ": " + _value + "\n");
//     }
// }

void Json::InsertArray(std::string key, std::vector<std::variant<int,std::string>> value){
    std::string arrayRes = _doubleQuote + key + _doubleQuote + ": " +"[";

    for(int i = 0; i < value.size(); i++){
        if(i > 0){
            arrayRes += ", ";
        }

        if(int* pValueEle = std::get_if<int>(&value[i])){
            arrayRes += std::to_string(*pValueEle);

        } else if(std::string* pValueEle = std::get_if<std::string>(&value[i])){
            std::string t = *pValueEle;
            if(t[0] == '['){
                arrayRes += *pValueEle;
            }else{
                std::string s = _doubleQuote + *pValueEle + _doubleQuote;
                arrayRes += s;
            }
        }
    }

    arrayRes += "]\n";

    if(_word.size() != 0){
        _word[_word.size()-1].insert(_word[_word.size()-1].size()-1,",");

        _word.push_back(arrayRes);
    }else{
        _word.push_back(arrayRes);
    }
}

std::string Json::MakeArray(std::vector<std::variant<int,std::string>> value){
    std::string res = "[";

    for(int i = 0; i < value.size(); i++){
        if(i > 0){
            res += ", ";
        }

        if(int* pValueEle = std::get_if<int>(&value[i])){
            res += std::to_string(*pValueEle);

        } else if(std::string* pValueEle = std::get_if<std::string>(&value[i])){
            std::string s = _doubleQuote + *pValueEle + _doubleQuote;
            res += s;
        }
    }

    res += "]";

    return res;
}

void Json::Update(){
    for(int i = 0; i < _word.size(); i++){
        _result.append(_word[i]);
    }

    _result.append("}");
}

std::string Json::GetJsonData(){
    return _result;
}