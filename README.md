## 삼각함수
### 삼각함수 for Window, IOS and Android


![image](https://user-images.githubusercontent.com/1701385/152289521-c2cbb930-1e99-430d-a78e-fc17112052ec.png)

삼각함수를 Windows 서버, IOS Android 클라에서 동일한 연산이 필요한 경우에 사용합니다.


### Floating Point 연산은 동일한것으로 판단되어지나

1. 삼각함수 (정밀도 불일치)
2. std::unordered_??? container의 순서불일치 (당연한의미이지만)
3. sort 함수에서의 비교 (>, =, < ) 의 명확한 설정

### 이중에서 삼각함수는 만들어야 합니다.

![image](https://user-images.githubusercontent.com/1701385/152289464-aaf6e176-218e-4557-8a0e-b522fdc10ee5.png)


삼각함수 중 특히 Tan 함수는 180도 간격으로 무한대로 값이 진행되어지므로 
그 주위에서의 정밀도를 맞추기는 쉽지 않습니다.

저도 인터넷을 검색하고 찾고 검증해서 정리한 코드를 사용하고 있습니다.

## Youtube

[![Video Label](https://img.youtube.com/vi/0aml9IwLUgE/0.jpg)](https://youtu.be/0aml9IwLUgE)

## Compile

Visual Studio (C++17) 에서 컴파일되도록 작성하였습니다.

## Description

- 크로스파이어 : RTS 전투엔진의 기반으로 사용하고 있습니다.

( 실제 크로스파이어 전투엔진은 C++ 으로 구성되어져 있읍니다. )
