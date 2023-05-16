//
// Created by gcc on 5/5/23.
//
#include <unordered_set>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> table;
        vector<string> result;
        for (string supply : supplies) {
            table.insert(supply);
        }
        bool target = true;
        int tar[100] = {0};
        int begi[100] = {0};
        while (target){
            target = false;
            for (int i = 0; i < ingredients.size(); i++) {
                if (tar[i] == 1)
                    continue;
                unordered_set<string>::iterator b;
                vector<string> in = ingredients[i];
                vector<string> compa = {"dc"};
                if (in == compa) {
                    cout << "exp" << endl;
                }

                for (begi[i]; begi[i] < in.size(); begi[i]++) {
                    string sup = in[begi[i]];
                    b = table.find(sup);
                    if (b == table.end())
                        break;
                }
                if (b != table.end()) {
                    table.insert(recipes[i]);
                    result.push_back(recipes[i]);
                    target = true;
                    tar[i] = 1;
                }
            }
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main () {
    Solution s;
//    ["pnqyy","ljsc","atmown","ryze","zvsd","idvevsjzy","qncqx","aenddh","faneqhp","jtibi","jkf","ltpmvct","ja","xxijkep","wnvg","aywfefnxht","nrz","mqhqrjela","raxck","n","lxzjrqxt","kt"]
    vector<string> recipes = {"p","ftb","gh","wsyslpn","pc","mliehbikls","raesrk","xpcleylr","ezichjo","ebsov","waerxr","r","krokmgm","xofkcj","fnz","yscylewq","dhm","dc","iqpfdvgeka","jrzjvn","ucxu","yhdpnxc","xy","z","pajmkq","jmujmdzog","u","kqkuyoapxq","g","tivnvyn","actetcbq","iebvg","kwrugxy","zsza","tqtxs","xvqn","ymnpylaady","adeczit"};
    vector<string> p = {"ja","kt","lxzjrqxt","jkf","xxijkep","n"};
    vector<string> ftb = {"jtibi","ljsc","pnqyy","qncqx","raxck","idvevsjzy","aywfefnxht","aenddh","lxzjrqxt","nrz","n","atmown","jkf","krokmgm","xy","ebsov","iebvg","dhm","tqtxs","p","iqpfdvgeka","xvqn","pc","mliehbikls","wsyslpn","adeczit","actetcbq","r","waerxr","g","fnz","kwrugxy","u","gh","z","ymnpylaady","pajmkq","xpcleylr","jmujmdzog","kqkuyoapxq","raesrk","zsza","ucxu"};
    vector<string> gh = {"ljsc","xxijkep","aywfefnxht","atmown","ryze","qncqx","jtibi","raxck","wnvg","nrz","ja","faneqhp","lxzjrqxt","zvsd","idvevsjzy","kt","aenddh","pnqyy","n","ltpmvct","mqhqrjela","jkf"};
    vector<string> wsyslpn = {"ryze","faneqhp","ljsc","n","raxck","idvevsjzy","lxzjrqxt","pnqyy","ja","qncqx","xxijkep","jkf","atmown","aywfefnxht","mqhqrjela","wnvg","kt","zvsd","aenddh","ltpmvct","jtibi","nrz","jmujmdzog","iqpfdvgeka","ezichjo","actetcbq","tivnvyn","fnz","ucxu","u","zsza","tqtxs","waerxr","krokmgm","pajmkq","ebsov","iebvg","pc"};
    vector<string> pc = {"lxzjrqxt","nrz","mqhqrjela","qncqx","atmown","wnvg","ja","ryze","xxijkep","jkf","idvevsjzy","n","aenddh","jtibi","pnqyy","aywfefnxht","kqkuyoapxq","fnz","gh","actetcbq","z","waerxr","iebvg","dc","yscylewq","p","xy","krokmgm","xofkcj"};
    vector<string> mliehbikls = {"cvmwtqrxw"};
    vector<string> raesrk = {"nrz","ezichjo","g","yscylewq","kwrugxy","z","xpcleylr","krokmgm","ucxu","fnz","pajmkq","pc","actetcbq","ftb","kqkuyoapxq"};
    vector<string> xpcleylr = {"ljsc","zvsd","raxck","n","idvevsjzy","ja","lxzjrqxt","pnqyy","atmown","kt","mqhqrjela","wnvg","aenddh","faneqhp","qncqx","jkf","ltpmvct","jtibi","nrz","ryze"};
    vector<string> ezichjo = {"aywfefnxht","lxzjrqxt","kt","ljsc","pnqyy","nrz","wnvg","ryze","zvsd","aenddh","n","jrzjvn","yhdpnxc","xy","ymnpylaady","kqkuyoapxq","iebvg","xofkcj","gh"};
    vector<string> ebsov = {"zvsd","idvevsjzy","atmown","jtibi","raxck","nrz","pnqyy","lxzjrqxt","jkf","kt","qncqx","n","aywfefnxht","ja"};
    vector<string> waerxr = {"ltpmvct","ja","ljsc"};
    vector<string> r = {"xxijkep","ljsc","jkf","kt","mqhqrjela","ryze","lxzjrqxt","raxck","zvsd","aenddh","qncqx","pnqyy","wnvg","ltpmvct","idvevsjzy","atmown","faneqhp","jtibi","nrz","n","ja","aywfefnxht","wsyslpn","zsza","z","ymnpylaady","raesrk","tivnvyn","adeczit","ftb","kwrugxy","yhdpnxc","p","actetcbq","u","ebsov","iebvg","dhm","xy","yscylewq","kqkuyoapxq","ezichjo","ucxu","fnz","jmujmdzog","pc","iqpfdvgeka","xofkcj"};
    vector<string> krokmgm = {"zvsd","wnvg","n","jtibi","ltpmvct","aywfefnxht","raxck","aenddh","jkf","atmown","qncqx","faneqhp","ljsc","pnqyy","kt","lxzjrqxt","ja","xxijkep","actetcbq","jmujmdzog","jrzjvn","raesrk","iqpfdvgeka","xy","tivnvyn","r","waerxr","g","p","kwrugxy"};
    vector<string> xofkcj = {"faneqhp","ltpmvct","aenddh","jtibi","atmown","ja","idvevsjzy","wnvg","n","pnqyy","ryze","nrz","mqhqrjela","qncqx","ljsc","gh","wsyslpn","dc"};
    vector<string> fnz = {"nrz","n","xxijkep","jkf","qncqx","aenddh","ljsc","atmown","jtibi","raxck","lxzjrqxt","ryze","ltpmvct","wnvg","idvevsjzy","ftb"};
    vector<string> yscylewq = {"jkf","raxck","faneqhp","jtibi","xxijkep","z","pc","mliehbikls","r","pajmkq","gh","wsyslpn","ymnpylaady","kqkuyoapxq","tivnvyn","iebvg","raesrk","krokmgm","g","dc","tqtxs","ftb","zsza","ebsov","waerxr","xpcleylr","u","actetcbq","xvqn","ucxu"};
    vector<string> dhm = {"aenddh","kt","atmown","ltpmvct","ryze","jtibi","zvsd","faneqhp","qncqx"};
    vector<string> dc = {"atmown","aenddh","nrz","wnvg","mqhqrjela","jkf","faneqhp","jtibi","ljsc","aywfefnxht","idvevsjzy","lxzjrqxt","kt","iqpfdvgeka"};
    vector<string> iqpfdvgeka = {"nrz","pnqyy"};
    vector<string> jrzjvn = {"lxzjrqxt","aenddh","kt","jtibi","faneqhp","ljsc","xxijkep","n","wnvg","qncqx","ltpmvct","mqhqrjela","waerxr","adeczit","ebsov","ezichjo","yscylewq","pajmkq","z","ucxu","actetcbq","dhm","xofkcj","r","zsza","kwrugxy","gh","krokmgm","wsyslpn","yhdpnxc","kqkuyoapxq","xy","jmujmdzog","g","iebvg","ftb","u","xpcleylr","tqtxs","fnz","xvqn","ymnpylaady","tivnvyn","raesrk"};
    vector<string> ucxu = {"kt","idvevsjzy","zvsd","mqhqrjela","aywfefnxht","ja","ryze","pnqyy","qncqx","ltpmvct","ljsc","raxck"};
    vector<string> yhdpnxc = {"n","ja","idvevsjzy","ltpmvct","lxzjrqxt","mqhqrjela","pnqyy","aywfefnxht","wnvg","raxck","jtibi","aenddh","zvsd","atmown","xxijkep","kt","qncqx","ryze","nrz","ljsc","faneqhp","jkf","tivnvyn","yscylewq","iebvg","kwrugxy","waerxr","r","ebsov","dhm","ymnpylaady","actetcbq","g"};
    vector<string> xy = {"idvevsjzy","nrz","atmown","mliehbikls","kqkuyoapxq","yscylewq","fnz","xvqn","g"};
    vector<string> z = {"jtibi","idvevsjzy","zvsd","ryze","ja","qncqx","kt","raxck","pnqyy","ljsc","atmown","ryze","zvsd","idvevsjzy","qncqx","aenddh","faneqhp","jtibi","jkf","ltpmvct","ja","xxijkep","wnvg","aywfefnxht","nrz","mqhqrjela","raxck","n","lxzjrqxt","kt""faneqhp","aenddh","nrz","xxijkep","jkf","lxzjrqxt","mqhqrjela","wnvg","n","atmown","aywfefnxht","pnqyy","ltpmvct","ljsc","ucxu","gh","xy","dhm","pajmkq","dc","ftb","mliehbikls","fnz","kqkuyoapxq","raesrk","xofkcj","jmujmdzog"};
//    "pajmkq","jmujmdzog","u","kqkuyoapxq","g","tivnvyn","actetcbq","iebvg","kwrugxy","zsza","tqtxs","xvqn","ymnpylaady","adeczit"
    vector<string> pajmkq = {"jtibi","pnqyy","ltpmvct","lxzjrqxt","faneqhp","kt","xxijkep","nrz"};
    vector<string> jmujmdzog = {"jtibi","pnqyy","ltpmvct","adeczit","p","ftb","iqpfdvgeka","xy","krokmgm","gh","actetcbq","fnz","wsyslpn","yscylewq","pajmkq","zsza","dc","kqkuyoapxq","xofkcj"};
    vector<string> u = {"kt","aenddh","wnvg","qncqx","n","ljsc","faneqhp","mqhqrjela"};
    vector<string> kqkuyoapxq = {"n","zvsd","mqhqrjela","aenddh"};
    vector<string> g = {"ja","faneqhp","jkf","ltpmvct","ryze","n","lxzjrqxt","ljsc","wnvg","aenddh","raxck","nrz","mqhqrjela","kt","pnqyy","idvevsjzy","ebsov","tivnvyn","ezichjo","jrzjvn","gh","kwrugxy","zsza","z","xofkcj","fnz","pajmkq","r"};
    vector<string> tivnvyn = {"ltpmvct","nrz","kt","aenddh","raxck","qncqx","jtibi","xxijkep","ljsc","mqhqrjela"};
    vector<string> actetcbq = {"ltpmvct","qncqx","nrz","zvsd","ja","idvevsjzy","faneqhp","atmown","ryze","lxzjrqxt","jtibi","raxck"};
    vector<string> iebvg = {"aenddh","ja","xxijkep","idvevsjzy","n","atmown","ltpmvct","aywfefnxht","ljsc","ryze","nrz","pnqyy"};
    vector<string> kwrugxy = {"ezichjo","g"};
    vector<string> zsza = {"aenddh","ltpmvct","faneqhp","jtibi","mqhqrjela","lxzjrqxt"};
    vector<string> tqtxs = {"ltpmvct","atmown","aywfefnxht","kt","aenddh","idvevsjzy","ljsc","jkf","qncqx","ja","faneqhp","jtibi","lxzjrqxt","n","nrz","ryze","xxijkep","mqhqrjela","pnqyy","wnvg"};
    vector<string> xvqn = {"atmown","pnqyy","ljsc"};
    vector<string> ymnpylaady = {"jtibi","ryze","aywfefnxht","lxzjrqxt","idvevsjzy","ljsc","ltpmvct","atmown","qncqx","n","ja","nrz","aenddh","raxck","faneqhp"};
    vector<string> adeczit = {"pnqyy","ljsc","atmown","ryze","zvsd","idvevsjzy","qncqx","aenddh","faneqhp","jtibi","jkf","ltpmvct","ja","gh","kwrugxy","kqkuyoapxq","mliehbikls","dc","jmujmdzog","yscylewq","yhdpnxc","xofkcj","actetcbq"};
//    "adeczit","actetcbq","r","waerxr","g","fnz","kwrugxy","u","gh","z","ymnpylaady","pajmkq","xpcleylr","jmujmdzog","kqkuyoapxq","raesrk","zsza","ucxu"};

    vector<vector<string>> ingredients;
    ingredients.push_back(p);
    ingredients.push_back(ftb);
    ingredients.push_back(gh);
    ingredients.push_back(wsyslpn);
    ingredients.push_back(pc);
    ingredients.push_back(mliehbikls);
    ingredients.push_back(raesrk);
    ingredients.push_back(xpcleylr);
    ingredients.push_back(ezichjo);
    ingredients.push_back(ebsov);
    ingredients.push_back(waerxr);
    ingredients.push_back(r);
    ingredients.push_back(krokmgm);
    ingredients.push_back(xofkcj);
    ingredients.push_back(fnz);
    ingredients.push_back(yscylewq);
    ingredients.push_back(dhm);
    ingredients.push_back(dc);
    ingredients.push_back(iqpfdvgeka);
    ingredients.push_back(jrzjvn);
    ingredients.push_back(ucxu);
    ingredients.push_back(yhdpnxc);
    ingredients.push_back(xy);
    ingredients.push_back(z);
    ingredients.push_back(pajmkq);
    ingredients.push_back(jmujmdzog);
    ingredients.push_back(u);
    ingredients.push_back(kqkuyoapxq);
    ingredients.push_back(g);
    ingredients.push_back(tivnvyn);
    ingredients.push_back(actetcbq);
    ingredients.push_back(iebvg);
    ingredients.push_back(kwrugxy);
    ingredients.push_back(zsza);
    ingredients.push_back(tqtxs);
    ingredients.push_back(xvqn);
    ingredients.push_back(ymnpylaady);
    ingredients.push_back(adeczit);

//    ingredients.push_back(bread);
    vector<string> supplies = {"pnqyy","ljsc","atmown","ryze","zvsd","idvevsjzy","qncqx","aenddh","faneqhp","jtibi","jkf","ltpmvct","ja","xxijkep","wnvg","aywfefnxht","nrz","mqhqrjela","raxck","n","lxzjrqxt","kt"};
    vector<string> result = s.findAllRecipes(recipes, ingredients, supplies);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " " ;    vector<string> xofkcj = {"faneqhp","ltpmvct","aenddh","jtibi","atmown","ja","idvevsjzy","wnvg","n","pnqyy","ryze","nrz","mqhqrjela","qncqx","ljsc","gh","wsyslpn","dc"};

        cout << endl;
    }
}
//
//[["ja","kt","lxzjrqxt","jkf","xxijkep","n"]
// ,["jtibi","ljsc","pnqyy","qncqx","raxck","idvevsjzy","aywfefnxht","aenddh","lxzjrqxt","nrz","n","atmown","jkf","krokmgm","xy","ebsov","iebvg","dhm","tqtxs","p","iqpfdvgeka","xvqn","pc","mliehbikls","wsyslpn","adeczit","actetcbq","r","waerxr","g","fnz","kwrugxy","u","gh","z","ymnpylaady","pajmkq","xpcleylr","jmujmdzog","kqkuyoapxq","raesrk","zsza","ucxu"]
// ,["ljsc","xxijkep","aywfefnxht","atmown","ryze","qncqx","jtibi","raxck","wnvg","nrz","ja","faneqhp","lxzjrqxt","zvsd","idvevsjzy","kt","aenddh","pnqyy","n","ltpmvct","mqhqrjela","jkf"],
// ["ryze","faneqhp","ljsc","n","raxck","idvevsjzy","lxzjrqxt","pnqyy","ja","qncqx","xxijkep","jkf","atmown","aywfefnxht","mqhqrjela","wnvg","kt","zvsd","aenddh","ltpmvct","jtibi","nrz","jmujmdzog","iqpfdvgeka","ezichjo","actetcbq","tivnvyn","fnz","ucxu","u","zsza","tqtxs","waerxr","krokmgm","pajmkq","ebsov","iebvg","pc"]
// ,["lxzjrqxt","nrz","mqhqrjela","qncqx","atmown","wnvg","ja","ryze","xxijkep","jkf","idvevsjzy","n","aenddh","jtibi","pnqyy","aywfefnxht","kqkuyoapxq","fnz","gh","actetcbq","z","waerxr","iebvg","dc","yscylewq","p","xy","krokmgm","xofkcj"]
// ,["cvmwtqrxw"]
// ,["nrz","ezichjo","g","yscylewq","kwrugxy","z","xpcleylr","krokmgm","ucxu","fnz","pajmkq","pc","actetcbq","ftb","kqkuyoapxq"]
// ,["ljsc","zvsd","raxck","n","idvevsjzy","ja","lxzjrqxt","pnqyy","atmown","kt","mqhqrjela","wnvg","aenddh","faneqhp","qncqx","jkf","ltpmvct","jtibi","nrz","ryze"]
// ,["aywfefnxht","lxzjrqxt","kt","ljsc","pnqyy","nrz","wnvg","ryze","zvsd","aenddh","n","jrzjvn","yhdpnxc","xy","ymnpylaady","kqkuyoapxq","iebvg","xofkcj","gh"]
// ,["zvsd","idvevsjzy","atmown","jtibi","raxck","nrz","pnqyy","lxzjrqxt","jkf","kt","qncqx","n","aywfefnxht","ja"]
// ,["ltpmvct","ja","ljsc"]
// ,["xxijkep","ljsc","jkf","kt","mqhqrjela","ryze","lxzjrqxt","raxck","zvsd","aenddh","qncqx","pnqyy","wnvg","ltpmvct","idvevsjzy","atmown","faneqhp","jtibi","nrz","n","ja","aywfefnxht","wsyslpn","zsza","z","ymnpylaady","raesrk","tivnvyn","adeczit","ftb","kwrugxy","yhdpnxc","p","actetcbq","u","ebsov","iebvg","dhm","xy","yscylewq","kqkuyoapxq","ezichjo","ucxu","fnz","jmujmdzog","pc","iqpfdvgeka","xofkcj"]
// ,["zvsd","wnvg","n","jtibi","ltpmvct","aywfefnxht","raxck","aenddh","jkf","atmown","qncqx","faneqhp","ljsc","pnqyy","kt","lxzjrqxt","ja","xxijkep","actetcbq","jmujmdzog","jrzjvn","raesrk","iqpfdvgeka","xy","tivnvyn","r","waerxr","g","p","kwrugxy"]
// ,["faneqhp","ltpmvct","aenddh","jtibi","atmown","ja","idvevsjzy","wnvg","n","pnqyy","ryze","nrz","mqhqrjela","qncqx","ljsc","gh","wsyslpn","dc"]
// ,["nrz","n","xxijkep","jkf","qncqx","aenddh","ljsc","atmown","jtibi","raxck","lxzjrqxt","ryze","ltpmvct","wnvg","idvevsjzy","ftb"]
// ,["jkf","raxck","faneqhp","jtibi","xxijkep","z","pc","mliehbikls","r","pajmkq","gh","wsyslpn","ymnpylaady","kqkuyoapxq","tivnvyn","iebvg","raesrk","krokmgm","g","dc","tqtxs","ftb","zsza","ebsov","waerxr","xpcleylr","u","actetcbq","xvqn","ucxu"]
// ,["aenddh","kt","atmown","ltpmvct","ryze","jtibi","zvsd","faneqhp","qncqx"]
// ,["atmown","aenddh","nrz","wnvg","mqhqrjela","jkf","faneqhp","jtibi","ljsc","aywfefnxht","idvevsjzy","lxzjrqxt","kt","iqpfdvgeka"]
// ,["nrz","pnqyy"]
// ,["lxzjrqxt","aenddh","kt","jtibi","faneqhp","ljsc","xxijkep","n","wnvg","qncqx","ltpmvct","mqhqrjela","waerxr","adeczit","ebsov","ezichjo","yscylewq","pajmkq","z","ucxu","actetcbq","dhm","xofkcj","r","zsza","kwrugxy","gh","krokmgm","wsyslpn","yhdpnxc","kqkuyoapxq","xy","jmujmdzog","g","iebvg","ftb","u","xpcleylr","tqtxs","fnz","xvqn","ymnpylaady","tivnvyn","raesrk"]
// ,["kt","idvevsjzy","zvsd","mqhqrjela","aywfefnxht","ja","ryze","pnqyy","qncqx","ltpmvct","ljsc","raxck"]
// ,["n","ja","idvevsjzy","ltpmvct","lxzjrqxt","mqhqrjela","pnqyy","aywfefnxht","wnvg","raxck","jtibi","aenddh","zvsd","atmown","xxijkep","kt","qncqx","ryze","nrz","ljsc","faneqhp","jkf","tivnvyn","yscylewq","iebvg","kwrugxy","waerxr","r","ebsov","dhm","ymnpylaady","actetcbq","g"]
// ,["idvevsjzy","nrz","atmown","mliehbikls","kqkuyoapxq","yscylewq","fnz","xvqn","g"]
// ,["jtibi","idvevsjzy","zvsd","ryze","ja","qncqx","kt","raxck",["pnqyy","ljsc","atmown","ryze","zvsd","idvevsjzy","qncqx","aenddh","faneqhp","jtibi","jkf","ltpmvct","ja","xxijkep","wnvg","aywfefnxht","nrz","mqhqrjela","raxck","n","lxzjrqxt","kt"]"faneqhp","aenddh","nrz","xxijkep","jkf","lxzjrqxt","mqhqrjela","wnvg","n","atmown","aywfefnxht","pnqyy","ltpmvct","ljsc","ucxu","gh","xy","dhm","pajmkq","dc","ftb","mliehbikls","fnz","kqkuyoapxq","raesrk","xofkcj","jmujmdzog"]
// ,["jtibi","pnqyy","ltpmvct","lxzjrqxt","faneqhp","kt","xxijkep","nrz"]
// ,["jtibi","pnqyy","ltpmvct","adeczit","p","ftb","iqpfdvgeka","xy","krokmgm","gh","actetcbq","fnz","wsyslpn","yscylewq","pajmkq","zsza","dc","kqkuyoapxq","xofkcj"]
// ,["kt","aenddh","wnvg","qncqx","n","ljsc","faneqhp","mqhqrjela"]
// ,["n","zvsd","mqhqrjela","aenddh"]
// ,["ja","faneqhp","jkf","ltpmvct","ryze","n","lxzjrqxt","ljsc","wnvg","aenddh","raxck","nrz","mqhqrjela","kt","pnqyy","idvevsjzy","ebsov","tivnvyn","ezichjo","jrzjvn","gh","kwrugxy","zsza","z","xofkcj","fnz","pajmkq","r"]
// ,["ltpmvct","nrz","kt","aenddh","raxck","qncqx","jtibi","xxijkep","ljsc","mqhqrjela"]
// ,["ltpmvct","qncqx","nrz","zvsd","ja","idvevsjzy","faneqhp","atmown","ryze","lxzjrqxt","jtibi","raxck"]
// ,["aenddh","ja","xxijkep","idvevsjzy","n","atmown","ltpmvct","aywfefnxht","ljsc","ryze","nrz","pnqyy"]
// ,["ezichjo","g"]
// ,["aenddh","ltpmvct","faneqhp","jtibi","mqhqrjela","lxzjrqxt"]
// ,["ltpmvct","atmown","aywfefnxht","kt","aenddh","idvevsjzy","ljsc","jkf","qncqx","ja","faneqhp","jtibi","lxzjrqxt","n","nrz","ryze","xxijkep","mqhqrjela","pnqyy","wnvg"]
// ,["atmown","pnqyy","ljsc"]
// ,["jtibi","ryze","aywfefnxht","lxzjrqxt","idvevsjzy","ljsc","ltpmvct","atmown","qncqx","n","ja","nrz","aenddh","raxck","faneqhp"]
// ,["pnqyy","ljsc","atmown","ryze","zvsd","idvevsjzy","qncqx","aenddh","faneqhp","jtibi","jkf","ltpmvct","ja","gh","kwrugxy","kqkuyoapxq","mliehbikls","dc","jmujmdzog","yscylewq","yhdpnxc","xofkcj","actetcbq"]]
//
//
//
//["p","ftb","gh","wsyslpn","pc","mliehbikls","raesrk","xpcleylr","ezichjo","ebsov","waerxr","r","krokmgm","xofkcj","fnz","yscylewq","dhm","dc","iqpfdvgeka","jrzjvn","ucxu","yhdpnxc","xy","z","pajmkq","jmujmdzog","u","kqkuyoapxq","g","tivnvyn","actetcbq","iebvg","kwrugxy","zsza","tqtxs","xvqn","ymnpylaady","adeczit"]
//["pnqyy","ljsc","atmown","ryze","zvsd","idvevsjzy","qncqx","aenddh","faneqhp","jtibi","jkf","ltpmvct","ja","xxijkep","wnvg","aywfefnxht","nrz","mqhqrjela","raxck","n","lxzjrqxt","kt"]
//
//["atmown","aenddh","nrz","wnvg","mqhqrjela","jkf","faneqhp","jtibi","ljsc","aywfefnxht","idvevsjzy","lxzjrqxt","kt","iqpfdvgeka"]