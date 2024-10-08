# [Gold V] 별 찍기 - 10 - 2447 

[문제 링크](https://www.acmicpc.net/problem/2447) 

### 성능 요약

메모리: 6748 KB, 시간: 132 ms

### 분류

분할 정복, 재귀

### 제출 일자

2024년 9월 22일 17:29:50

### 문제 설명

<p>재귀적인 패턴으로 별을 찍어 보자. N이 3의 거듭제곱(3, 9, 27, ...)이라고 할 때, 크기 N의 패턴은 N×N 정사각형 모양이다.</p>

<p>크기 3의 패턴은 가운데에 공백이 있고, 가운데를 제외한 모든 칸에 별이 하나씩 있는 패턴이다.</p>

<pre>***
* *
***</pre>

<p>N이 3보다 클 경우, 크기 N의 패턴은 공백으로 채워진 가운데의 (N/3)×(N/3) 정사각형을 크기 N/3의 패턴으로 둘러싼 형태이다. 예를 들어 크기 27의 패턴은 예제 출력 1과 같다.</p>

### 입력 

 <p>첫째 줄에 N이 주어진다. N은 3의 거듭제곱이다. 즉 어떤 정수 k에 대해 N=3<sup>k</sup>이며, 이때 1 ≤ k < 8이다.</p>

### 출력 

 <p>첫째 줄부터 N번째 줄까지 별을 출력한다.</p>

### 코멘트

 <p>분할 정복을 통해 별을 찍는 문제이다. 9등분을 계속 내서 3x3이 되었을때 별을 찍는 방식으로 가운데는 별을 찍지 않는다. 9등분을 내야되서 재귀적으로 짠 내 코드는 재귀함수내에 함수가 8개가 필요했다. 나는 배열을 통해 별을 저장했다가 재귀가 싹 끝나고 별을 출력했는데 배열없이 풀 수 있으면 메모리 소모가 거의 없어질거같다.</p>
