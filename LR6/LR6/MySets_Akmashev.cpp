#include "MySet.h";
#include "SetHeader.h";
#include "SetLab4_Akmashev.h";
#include "SetLab5_Akmashev.h";
#include <chrono>;

int main() {
	srand(time(nullptr));
	setlocale(LC_ALL, "Russian");
    cout << "Введите мощность создаваемых множеств" << endl;

    int N;
    cin >> N;

    cout << "\n\nСтатистика\n\n";
    cout << "Операция \t На указателях \tНа ООП \t\t Контейнер List \t Контейнер Set \n";

    auto start11 = chrono::high_resolution_clock::now();
    Element* setA1 = generateSet(N, 10, 6 * N, 3);
    auto end11 = chrono::high_resolution_clock::now();
    auto timeTest11 = chrono::duration_cast<chrono::duration < double>>(end11 - start11);

    auto start12 = chrono::high_resolution_clock::now();
    MySet setA2 = MySet();
    setA2.generateSet(N, 10, 6 * N, 3);
    auto end12 = chrono::high_resolution_clock::now();
    auto timeTest12 = chrono::duration_cast<chrono::duration < double>>(end12 - start12);

    auto start13 = chrono::high_resolution_clock::now();
    SetList setA3 = SetList();
    setA3.generateSet(N, 10, 6 * N, 3);
    auto end13 = chrono::high_resolution_clock::now();
    auto timeTest13 = chrono::duration_cast<chrono::duration < double>>(end13 - start13);

    auto start14 = chrono::high_resolution_clock::now();
    SetSet setA4 = SetSet();
    setA4.generateSet(N, 10, 6 * N, 3);
    auto end14 = chrono::high_resolution_clock::now();
    auto timeTest14 = chrono::duration_cast<chrono::duration < double>>(end14 - start14);

    Element* setB1 = generateSet(N, 10, 6 * N, 3);
    MySet setB2 = MySet();
    setB2.generateSet(N, 10, 6 * N, 3);
    SetList setB3 = SetList();
    setB3.generateSet(N, 10, 6 * N, 3);
    SetSet setB4 = SetSet();
    setB4.generateSet(N, 10, 6 * N, 3);

    cout << "1.Создание \t " << to_string((timeTest11).count() * 10000) << "\t" << to_string((timeTest12).count() * 10000)
        << " \t " << to_string((timeTest13).count() * 10000) << " \t\t " << to_string((timeTest14).count() * 10000) << "\n";
    cout << "______________________________________________________________________________________________" << endl;

    auto start21 = chrono::high_resolution_clock::now();
    SetPower(setA1);
    auto end21 = chrono::high_resolution_clock::now();
    auto timeTest21 = chrono::duration_cast<chrono::duration < double>>(end21 - start21);

    auto start22 = chrono::high_resolution_clock::now();
    setA2.SetPower();
    auto end22 = chrono::high_resolution_clock::now();
    auto timeTest22 = chrono::duration_cast<chrono::duration < double>>(end22 - start22);

    auto start23 = chrono::high_resolution_clock::now();
    setA3.SetPower();
    auto end23 = chrono::high_resolution_clock::now();
    auto timeTest23 = chrono::duration_cast<chrono::duration < double>>(end23 - start23);

    auto start24 = chrono::high_resolution_clock::now();
    setA4.SetPower();
    auto end24 = chrono::high_resolution_clock::now();
    auto timeTest24 = chrono::duration_cast<chrono::duration < double>>(end24 - start24);

    cout << "2.Мощность \t " << to_string((timeTest21).count() * 10000) << "\t" << to_string((timeTest22).count() * 10000)
        << " \t " << to_string((timeTest23).count() * 10000) << " \t\t " << to_string((timeTest24).count() * 10000) << "\n";
    cout << "______________________________________________________________________________________________" << endl;

    auto start31 = chrono::high_resolution_clock::now();
    isSubset(setA1, setA1);
    auto end31 = chrono::high_resolution_clock::now();
    auto timeTest31 = chrono::duration_cast<chrono::duration < double>>(end31 - start31);

    auto start32 = chrono::high_resolution_clock::now();
    MySet().isSubset(setA2, setA2);
    auto end32 = chrono::high_resolution_clock::now();
    auto timeTest32 = chrono::duration_cast<chrono::duration < double>>(end32 - start32);

    auto start33 = chrono::high_resolution_clock::now();
    SetList().isSubset(setA3, setA3);
    auto end33 = chrono::high_resolution_clock::now();
    auto timeTest33 = chrono::duration_cast<chrono::duration < double>>(end33 - start33);

    auto start34 = chrono::high_resolution_clock::now();
    SetSet().isSubset(setA4, setA4);
    auto end34 = chrono::high_resolution_clock::now();
    auto timeTest34 = chrono::duration_cast<chrono::duration < double>>(end34 - start34);

    cout << "3.A|A \t\t " << to_string((timeTest31).count() * 10000) << "\t" << to_string((timeTest32).count() * 10000) << " \t "
        << to_string((timeTest33).count() * 10000) << " \t\t " << to_string((timeTest34).count() * 10000) << "\n";
    cout << "______________________________________________________________________________________________" << endl;

    auto start41 = chrono::high_resolution_clock::now();
    isSubset(setA1, setB1);
    auto end41 = chrono::high_resolution_clock::now();
    auto timeTest41 = chrono::duration_cast<chrono::duration < double>>(end41 - start41);

    auto start42 = chrono::high_resolution_clock::now();
    MySet().isSubset(setA2, setB2);
    auto end42 = chrono::high_resolution_clock::now();
    auto timeTest42 = chrono::duration_cast<chrono::duration < double>>(end42 - start42);

    auto start43 = chrono::high_resolution_clock::now();
    SetList().isSubset(setA3, setB3);
    auto end43 = chrono::high_resolution_clock::now();
    auto timeTest43 = chrono::duration_cast<chrono::duration < double>>(end43 - start43);

    auto start44 = chrono::high_resolution_clock::now();
    SetSet().isSubset(setA4, setB4);
    auto end44 = chrono::high_resolution_clock::now();
    auto timeTest44 = chrono::duration_cast<chrono::duration < double>>(end44 - start44);

    cout << "4.A|B \t\t " << to_string((timeTest41).count() * 10000) << "\t" << to_string((timeTest42).count() * 10000)
        << " \t " << to_string((timeTest43).count() * 10000) << " \t\t " << to_string((timeTest44).count() * 10000) << "\n";
    cout << "______________________________________________________________________________________________" << endl;

    auto start51 = chrono::high_resolution_clock::now();
    isEqual(setA1, setA1);
    auto end51 = chrono::high_resolution_clock::now();
    auto timeTest51 = chrono::duration_cast<chrono::duration < double>>(end51 - start51);

    auto start52 = chrono::high_resolution_clock::now();
    MySet().isEqual(setA2, setA2);
    auto end52 = chrono::high_resolution_clock::now();
    auto timeTest52 = chrono::duration_cast<chrono::duration < double>>(end52 - start52);

    auto start53 = chrono::high_resolution_clock::now();
    SetList().isEqual(setA3, setA3);
    auto end53 = chrono::high_resolution_clock::now();
    auto timeTest53 = chrono::duration_cast<chrono::duration < double>>(end53 - start53);

    auto start54 = chrono::high_resolution_clock::now();
    SetSet().isEqual(setA4, setA4);
    auto end54 = chrono::high_resolution_clock::now();
    auto timeTest54 = chrono::duration_cast<chrono::duration < double>>(end54 - start54);

    cout << "5.A=A \t\t " << to_string((timeTest51).count() * 10000) << "\t" << to_string((timeTest52).count() * 10000)
        << " \t " << to_string((timeTest53).count() * 10000) << " \t\t " << to_string((timeTest54).count() * 10000) << "\n";
    cout << "______________________________________________________________________________________________" << endl;

    auto start61 = chrono::high_resolution_clock::now();
    isEqual(setA1, setB1);
    auto end61 = chrono::high_resolution_clock::now();
    auto timeTest61 = chrono::duration_cast<chrono::duration < double>>(end61 - start61);

    auto start62 = chrono::high_resolution_clock::now();
    MySet().isEqual(setA2, setB2);
    auto end62 = chrono::high_resolution_clock::now();
    auto timeTest62 = chrono::duration_cast<chrono::duration < double>>(end62 - start62);

    auto start63 = chrono::high_resolution_clock::now();
    SetList().isEqual(setA3, setB3);
    auto end63 = chrono::high_resolution_clock::now();
    auto timeTest63 = chrono::duration_cast<chrono::duration < double>>(end63 - start63);

    auto start64 = chrono::high_resolution_clock::now();
    SetSet().isEqual(setA4, setB4);
    auto end64 = chrono::high_resolution_clock::now();
    auto timeTest64 = chrono::duration_cast<chrono::duration < double>>(end64 - start64);

    cout << "6.A=B \t\t " << to_string((timeTest61).count() * 10000) << "\t" << to_string((timeTest62).count() * 10000)
        << " \t " << to_string((timeTest63).count() * 10000) << " \t\t " << to_string((timeTest64).count() * 10000) << "\n";
    cout << "______________________________________________________________________________________________" << endl;

    auto start71 = chrono::high_resolution_clock::now();
    mergeSets(setA1, setB1);
    auto end71 = chrono::high_resolution_clock::now();
    auto timeTest71 = chrono::duration_cast<chrono::duration < double>>(end71 - start71);

    auto start72 = chrono::high_resolution_clock::now();
    MySet().mergeSets(setA2, setB2);
    auto end72 = chrono::high_resolution_clock::now();
    auto timeTest72 = chrono::duration_cast<chrono::duration < double>>(end72 - start72);

    auto startTest73 = chrono::high_resolution_clock::now();
    SetList().mergeSets(setA3, setB3);
    auto finishTest73 = chrono::high_resolution_clock::now();
    auto timeTest73 = chrono::duration_cast<chrono::duration < double>>(finishTest73 - startTest73);

    auto startTest74 = chrono::high_resolution_clock::now();
    SetSet().mergeSets(setA4, setB4);
    auto finishTest74 = chrono::high_resolution_clock::now();
    auto timeTest74 = chrono::duration_cast<chrono::duration < double>>(finishTest74 - startTest74);

    cout << "7.A+B \t\t " << to_string((timeTest71).count() * 10000) << "\t" << to_string((timeTest72).count() * 10000)
        << " \t " << to_string((timeTest73).count() * 10000) << " \t\t " << to_string((timeTest74).count() * 10000) << "\n";
    cout << "______________________________________________________________________________________________" << endl;

    auto startTest81 = chrono::high_resolution_clock::now();
    sameOfSets(setA1, setB1);
    auto finishTest81 = chrono::high_resolution_clock::now();
    auto timeTest81 = chrono::duration_cast<chrono::duration < double>>(finishTest81 - startTest81);

    auto startTest82 = chrono::high_resolution_clock::now();
    MySet().sameOfSets(setA2, setB2);
    auto finishTest82 = chrono::high_resolution_clock::now();
    auto timeTest82 = chrono::duration_cast<chrono::duration < double>>(finishTest82 - startTest82);

    auto startTest83 = chrono::high_resolution_clock::now();
    SetList().sameOfSets(setA3, setB3);
    auto finishTest83 = chrono::high_resolution_clock::now();
    auto timeTest83 = chrono::duration_cast<chrono::duration < double>>(finishTest83 - startTest83);

    auto startTest84 = chrono::high_resolution_clock::now();
    SetSet().sameOfSets(setA4, setB4);
    auto finishTest84 = chrono::high_resolution_clock::now();
    auto timeTest84 = chrono::duration_cast<chrono::duration < double>>(finishTest84 - startTest84);

    cout << "8.A/\\B \t\t " << to_string((timeTest81).count() * 10000) << "\t" << to_string((timeTest82).count() * 10000)
        << " \t " << to_string((timeTest83).count() * 10000) << " \t\t " << to_string((timeTest84).count() * 10000) << "\n";
    cout << "______________________________________________________________________________________________" << endl;

    auto startTest91 = chrono::high_resolution_clock::now();
    diffOfSets(setA1, setB1);
    auto finishTest91 = chrono::high_resolution_clock::now();
    auto timeTest91 = chrono::duration_cast<chrono::duration < double>>(finishTest91 - startTest91);

    auto startTest92 = chrono::high_resolution_clock::now();
    MySet().diffOfSets(setA2, setB2);
    auto finishTest92 = chrono::high_resolution_clock::now();
    auto timeTest92 = chrono::duration_cast<chrono::duration < double>>(finishTest92 - startTest92);

    auto startTest93 = chrono::high_resolution_clock::now();
    SetList().diffOfSets(setA3, setB3);
    auto finishTest93 = chrono::high_resolution_clock::now();
    auto timeTest93 = chrono::duration_cast<chrono::duration < double>>(finishTest93 - startTest93);

    auto startTest94 = chrono::high_resolution_clock::now();
    SetSet().diffOfSets(setA4, setB4);
    auto finishTest94 = chrono::high_resolution_clock::now();
    auto timeTest94 = chrono::duration_cast<chrono::duration < double>>(finishTest94 - startTest94);

    cout << "9.A-B \t\t " << to_string((timeTest91).count() * 10000) << "\t" << to_string((timeTest92).count() * 10000)
        << " \t " << to_string((timeTest93).count() * 10000) << " \t\t " << to_string((timeTest94).count() * 10000) << "\n";
    cout << "______________________________________________________________________________________________" << endl;

    auto startTest101 = chrono::high_resolution_clock::now();
    symDiffOfSets(setA1, setB1);
    auto finishTest101 = chrono::high_resolution_clock::now();
    auto timeTest101 = chrono::duration_cast<chrono::duration < double>>(finishTest101 - startTest101);

    auto startTest102 = chrono::high_resolution_clock::now();
    MySet().symDiffOfSets(setA2, setB2);
    auto finishTest102 = chrono::high_resolution_clock::now();
    auto timeTest102 = chrono::duration_cast<chrono::duration < double>>(finishTest102 - startTest102);

    auto startTest103 = chrono::high_resolution_clock::now();
    SetList().symDiffOfSets(setA3, setB3);
    auto finishTest103 = chrono::high_resolution_clock::now();
    auto timeTest103 = chrono::duration_cast<chrono::duration < double>>(finishTest103 - startTest103);

    auto startTest104 = chrono::high_resolution_clock::now();
    SetSet().symDiffOfSets(setA4, setB4);
    auto finishTest104 = chrono::high_resolution_clock::now();
    auto timeTest104 = chrono::duration_cast<chrono::duration < double>>(finishTest104 - startTest104);

    cout << "10.A\\B \t\t " << to_string((timeTest101).count() * 10000) << "\t" << to_string((timeTest102).count() * 10000) 
        << " \t " << to_string((timeTest103).count() * 10000) << " \t\t " << to_string((timeTest104).count() * 10000) << "\n";
    return 0;
}