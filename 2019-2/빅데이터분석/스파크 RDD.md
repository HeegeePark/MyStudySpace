# Spark RDD

## RDD 소개
- RDD (Resilient Distributed Dataset)는 그 줄임말에서 알 수 있듯이 데이터를 저장하고 있는 DataSet이며, 여러 컴퓨터에 분산해서 사용해서 사용할 수 있다는 점이 특징
	- Resilient - 작업이 실패하지 않도록 fault tolerent, 즉 어느 한 노드에서 작업이 실패하면 다른 노드에서 실행
	- Distributed - 클라스터로 구성된 여러 노드에 분산해서 처리
	- Dataset - 데이터 구조

## RDD 생성
### List에서 RDD 생성하기
- sparkcontext.parallelize()함수를 사용하여 RDD를 생성한다.
```
myList=[1,2,3,4,5,6,7]
myRdd1 = spark.sparkContext.parallelize(myList)

myRdd1.take(3)
```

### 파일에서 RDD 생성하기
- 현재 작업 디렉토리 아래에 'data/' 디렉토리를 만들고 아래 파일을 생성한다. 
- 파일 내용은 wikipedia에서 Apache spark를 검색한 후 첫 문단을 복사한 것, 일부러 3째줄은 한글, 4째 줄은 같은 단어를 반복해서 추가.
```
%%writefile data/ds_spark_wiki.txt
Wikipedia
Apache Spark is an open source cluster computing framework.
아파치 스파크는 오픈 소스 클러스터 컴퓨팅 프레임워크이다.
Apache Spark Apache Spark Apache Spark Apache Spark
아파치 스파크 아파치 스파크 아파치 스파크 아파치 스파크
Originally developed at the University of California, Berkeley's AMPLab,
the Spark codebase was later donated to the Apache Software Foundation,
which has maintained it since.
Spark provides an interface for programming entire clusters with
implicit data parallelism and fault-tolerance.
```

- 파일에서  RDD를 생성하기 위해서는 앞서와 같이 SparkContext를 사용
-  파일명을 textFile() 함수 인자로 넣어서 만들기
```
myRdd2=spark.sparkContext\
    .textFile(os.path.join("data","ds_spark_wiki.txt"))
```
```
myRdd2.first()	# first는 첫 데이터만 조회하는 action 함수
```

- **RDD와 Spark Dataframe를 만드는 함수는 서로 다름.**
	- SparkSession.sparkContext.textFile()	: 'SparkContext'를 사용하므로 RDD를 생성
	- SparkSession.read.text()	: DataFrame을 생성

```
import os
myDf=spark.read.text(os.path.join("data", "ds_spark_wiki.txt"))
print myDf.first()
```
Row(value=u'Wikipedia')
```
print type(myDf)
```
<class 'pyspark.sql.dataframe.DataFrame'>

- **csv에서 RDD 생성하기**
```
#csv 만들기
%%writefile ./data/ds_spark_2cols.csv
35, 2
40, 27
12, 38
15, 31
21, 1
14, 19
46, 1
10, 34
28, 3
48, 1
16, 2
30, 3
32, 2
48, 1
31, 2
22, 1
12, 3
39, 29
19, 37
25, 2
```

-  take()를 하면 그 결과는 리스트가 된다. 아래에서 보듯이 파일의 각 라인이 묶여서 리스트의 한 요소로 만들어짐.
```
myRdd4 = spark.sparkContext\
    .textFile(os.path.join("data","ds_spark_2cols.csv"))
myRdd4.take(5)
```
[u'35, 2', u'40, 27', u'12, 38', u'15, 31', u'21, 1']
```
myList=myRdd4.take(5)
print type(myList)
```

- 2차원 리스트로 만드려면, map()함수를 사용
	- 모든 줄을 반복:
      한 줄line을 읽는다.
      줄line을 컴마(,)로 분리한다.
      줄line을 리스트로 만든다.
```
myRdd5 = myRdd4.map(lambda line: line.split(',')) # 한 줄을 가져와서 , 기준으로 분리.
myRdd5.take(5)
```
[[u'35', u' 2'],
 [u'40', u' 27'],
 [u'12', u' 38'],
 [u'15', u' 31'],
 [u'21', u' 1']]

## RDD API
- RDD는 데이터 변환Transformations, 연산Actions으로 구분할 수 있음.
- Dataframe의 Transformer, Estimator와 비교될 수 있음.

### 변환 변환Transformations
- lazy연산을 함. 즉, 실제 변환은 action이 수행되는 시점까지 늦추어져서 이루어지고 변환 결과는 RDD 또는 seq(RDD)로 만들어짐
	- map(fn):	요소별로 fn을 적용해서 결과 RDD 돌려줌
		- .map(lambda x: x.split(' ')
	- filter(fn):	요소별로 선별하여 fn을 적용해서 결과 RDD 돌려줌
		- .filter(lambda x: "Spark" in x)
	- flatMap(fn):	요소별로 fn을 적용하고, flat해서 결과 RDD 돌려줌
		- .flatMap(lambda x: x.split(' '))
		- 2차원 이상의 다차원 맵을 1차원으로 변환해줌(=flat)
	- groupByKey():	key를 그룹해서 iterator를 돌려줌.

### actions
- RDD를 값으로 변환
	- reduce(fn)	요소별로 fn을 사용해서 줄여서 결과 list를 돌려줌	reduce(lambda x,y:x+y)
	- collect()	모든 요소를 결과 list로 돌려줌	
	- count()	요소의 갯수를 결과 list로 돌려줌	
	- take(n)	collect()는 전체이지만, n개만 돌려줌	take(1)
	- countByKey()	key별 갯수를 세는 함수	countByKey().items()
	- foreach(fn)	각 데이터 항목에 함수fn을 적용	

### 우선 Python 함수로 해보기

- **map() 함수를 사용해 보기**
	- for문이 사라진다는 점에 유의한다.
	-  map() 함수의 인자는 2개
	- 두번째 인자는 처리하려는 데이터
		- map()	각 데이터 요소에 함수를 적용해서 list를 반환	map(fn,data)
	- filter()	각 데이터 요소에 함수의 결과 True를 선택해서 반환	filter(fn, data)
	- reduce()	각 데이터 요소에 함수를 적용해서 list를 반환	reduce(fn, data)

```
celsius = [39.2, 36.5, 37.3, 37.8]
def c2f(c):
    return (float(9)/5)*c + 32

f=map(c2f, celsius)
print f
```
[102.56, 97.7, 99.14, 100.03999999999999]

-  lambda는 무명 함수이므로 함수 선언이 별도 필요 X 
-  처리 결과는 'return'을 사용하지 않아도 반환
-  이름이 없다는 특징
```
def f(x):
    return x*2
y=f(1)
print y
```
2
```
y=lambda x:x*2
print y(1)
```
2
```
map(lambda c:(float(9)/5)*c + 32, celsius)
```
[102.56, 97.7, 99.14, 100.03999999999999]

- 문자열에 map 사용해보기
	- **문자열** "Hello World"을 사용하면, 각 **철자**를 map()함수의 인자로 처리해서 split()
	- **list** ["Hello World"]를 사용하면, 각 **단어**를 map()함수의 인자로 처리해서 split()
```
# 요소가 철자
sentence = "Hello World"
map(lambda x:x.split(),sentence)
```
[['H'], ['e'], ['l'], ['l'], ['o'], [], ['W'], ['o'], ['r'], ['l'], ['d']]
```
sentence = ["Hello World", "Good Morining"]
map(lambda x:x.split(),sentence)
```
[['Hello', 'World'], ['Good', 'Morining']]

- **filter()**
	- 데이터를 선별

```
fib = [0,1,1,2,3,5,8,13,21,34,55]
result = filter(lambda x: x % 2, fib)
print result
```
[1, 1, 3, 5, 13, 21, 55]

- **reduce()**
	- 함수와 데이터 2개의 인자를 받음.
	- 반복문 필요 X
	
```
# x가 앞의 x+y값으로 초기화(like 누적합 원리)
reduce(lambda x, y: x+y, range(1,101))
```
5050

## RDD 사용하기
### map
- map()을 사용해서 제곱
- 반환값은 RDD
- collect 사용해서 출력
```
nRdd = spark.sparkContext.parallelize([1, 2, 3, 4])
squared = nRdd.map(lambda x: x * x)
print squared
```
 PythonRDD[4] at RDD at PythonRDD.scala:48
	- RDD를 프린트한다고 내부가 보이지 X (내부를 볼려면 action 함수 사용할 것)

```
print squared.collect()
```
[1, 4, 9, 16]

### reduce
- RDD 사용안하고 python reduce() 사용 예
-  lamdba함수를 사용해서 입력 데이터 2개씩을 서로 더해서 x+y 결과 값을 만들어 냄.
```
myRdd100 = spark.sparkContext.parallelize(range(1,101))
myRdd100.reduce(lambda x,y: x+y)
```
5050

### 단순 통계 기능
- 텍스트데이터와 달리 정량데이터로부터 sum, min, max, 표준편차 등 서술통계를 계산 가능
```
print "sum: ",nRdd.sum()
print "min: ",nRdd.min()
print "max: ", nRdd.max()
print "standard deviation:", nRdd.stdev()
print "variance: ", nRdd.variance()
```
sum:  10
min:  1
max:  4
standard deviation: 1.11803398875
variance:  1.25

### filter()
- 조건에 맞는 문장 분리하기
```
myRdd_spark=myRdd2.filter(lambda line: "Spark" in line)
print "How many lines having 'Spark': ",myRdd_spark.count()
```
How many lines having 'Spark':  4

- 한글을 filter하려면 앞에 u를 붙여준다. u는 유니코드를 의미한다.
```
myRdd_unicode = myRdd2.filter(lambda line: u"스파크" in line)
print myRdd_unicode.first()
```
아파치 스파크는 오픈 소스 클러스터 컴퓨팅 프레임워크이다.

#### filter()를 사용해서 **stopwords** 제거하기
- 문장 안에 stopwords를 포함한 경우는 제거되지 않음.
- 따라서  flatMap()을 하고 단어에 대해 불용어를 제거해야 함.
	- 불용어는 단어빈도를 계산하면서 제거하고 싶은 단어
- 불용어는 빈도를 세어도 의미가 없는 대명사 (이, 그, 저...) 또는 한 글자 단어 (등...)이 될 수 있음
- 처리 방법은 한글 유니코드로 처리함.
```
stopwords = ['is','am','are','the','for','a', 'an', 'at']		# 불용어 설정
myRdd_stop = myRdd2.flatMap(lambda x:x.split())\
                    .filter(lambda x: x not in stopwords)
```

- stopwords를 제거한 문장을 출력하면 collect() 함수는 문장을 수집하여, list로 만들어줌 
- list를 하나씩 반복문 for를 사용하여 출력한다.
```
for words in myRdd_stop.collect():
    print words,
```
Wikipedia Apache Spark open source cluster computing framework. 아파치 스파크는 오픈 소스 클러스터 컴퓨팅 프레임워크이다. Apache Spark Apache Spark Apache Spark Apache Spark 아파치 스파크 아파치 스파크 아파치 스파크 아파치 스파크 Originally developed University of California, Berkeley's AMPLab, Spark codebase was later donated to Apache Software Foundation, which has maintained it since. Spark provides interface programming entire clusters with implicit data parallelism and fault-tolerance.

### foreach()
- foreach()는 action
- action 함수들과 달리 반환 값이 없음.
- 유사한 기능이 map()
- 각 요소에 대해 계산을 하고, 값을 반환
```
spark.sparkContext.parallelize([1, 2, 3, 4, 5]).foreach(lambda x: x + 1)
spark.sparkContext.parallelize([1, 2, 3, 4, 5]).map(lambda x: x + 1).collect()
```
[2, 3, 4, 5, 6]

- 다음은 foreach()는 f() 함수를 호출하여 실행
-  그 결과 각 요소를 print()
```
def f(x): print(x)
spark.sparkContext.parallelize([1, 2, 3, 4, 5]).foreach(f)
```

### map()함수로 단어 분리
- map 함수를 사용해서 문서를 문장으로 분리하기
- 문서파일이 10개 문장을 포함하고 있으므로, count()는 10개를 출력
```
myRdd2=spark.sparkContext\
    .textFile(os.path.join("data","ds_spark_wiki.txt"))
sentences=myRdd2.map(lambda x:x.split(" "))
sentences.count()
```
10

- 사용자 함수, 즉 사용자가 만든 mySplit() 함수를 사용해 map()을 수행
- 이와 같이 lambda를 사용하지 않고, 사용자함수로 map()을 사용할 수 있음
- lambda는 한 줄의 명령문만 가지게 되므로, 여러 명령문으로 함수를 만드는 경우 사용자함수를 만들어 유용하게 사용 가능.
```
def mySplit(x):
    return x.split(" ")

sentences2=myRdd2.map(mySplit)

sentences2.count()
```
10

- take() 함수를 사용해 수집
- 인자 3을 넣어 갯수를 정하고, 리스트에 담겨져 있으므로, 이를 풀어서 출력하기 위해서는 for문을 사용해야 함.
- 리스트에 담겨져 있는 데이터를 살펴보면, 단어로 분리되어 있는 것을 알 수 있음.
```
sentences.take(3)
```
[[u'Wikipedia'],
 [u'Apache',
  u'Spark',
  u'is',
  u'an',
  u'open',
  u'source',
  u'cluster',
  u'computing',
  u'framework.'],
 [u'\uc544\ud30c\uce58',
  u'\uc2a4\ud30c\ud06c\ub294',
  u'\uc624\ud508',
  u'\uc18c\uc2a4',
  u'\ud074\ub7ec\uc2a4\ud130',
  u'\ucef4\ud4e8\ud305',
  u'\ud504\ub808\uc784\uc6cc\ud06c\uc774\ub2e4.']]

- 리스트에는 문장이 분리된 단어가 요소로 담겨져 있으므로, for문을 중첩해서 사용해야 단어를 출력할 수 있음.
- for문을 사용해야 유니코드가 아닌 한글 출력 가능.
```
for line in sentences.collect():
    for word in line:
        print word,
    print "\n-----"
```

```
Wikipedia 
-----
Apache Spark is an open source cluster computing framework. 
-----
아파치 스파크는 오픈 소스 클러스터 컴퓨팅 프레임워크이다. 
-----
Apache Spark Apache Spark Apache Spark Apache Spark 
-----
아파치 스파크 아파치 스파크 아파치 스파크 아파치 스파크 
-----
Originally developed at the University of California, Berkeley's AMPLab, 
-----
the Spark codebase was later donated to the Apache Software Foundation, 
-----
which has maintained it since. 
-----
Spark provides an interface for programming entire clusters with 
-----
implicit data parallelism and fault-tolerance.
``` 

- 각 문장의 철자 갯수를 세어보기
- 철자는  len()함수를 사용
```
len("Apache Spark is an open source cluster computing framework")
```
58

```
myRdd2.map(lambda s:len(s)).collect()
```
[9, 59, 32, 51, 31, 72, 71, 30, 64, 46]

- 리스트에서 RDD를 만들어 간단한 문자처리 기능으로 대소문자 변환이나 교체를 해보기.
```
myList=["this is","a line"]
_rdd=spark.sparkContext.parallelize(myList)

wordsRdd=_rdd.map(lambda x:x.split())
print wordsRdd.collect()
```
[['this', 'is'], ['a', 'line']]

```
repRdd=_rdd.map(lambda x:x.replace("a","AA"))
repRdd.take(10)
```
['this is', 'AA line']
	- 출력되는 결과만 바꾼것이고, 실제 RDD는 수정 불가능

- 첫글자를 대문자로 만들어서 출력하기
-  's'.upper()는 철자 's'를 대문자로 출력하는 함수

- 첫째 요소 x[0]는 리스트 각 요소의 첫째 단어 'this', 'a'를 대문자로 변환
```
upperRDD =wordsRdd.map(lambda x: x[0].upper())
print upperRDD.collect()
```
['THIS', 'A']

- 리스트의 모든 단어를 대문자로 바꾸려면 for문을 사용
```
upper2RDD =wordsRdd.map(lambda x: [i.upper() for i in x])
print upper2RDD.collect()
```
[['THIS', 'IS'], ['A', 'LINE']]

### pipeline
- 파이프라인은 transformation(예: map()), action(예: collect()) 함수를 연이어 적용하는 방식
- 결과를 받은 후 다음 함수를 단계별로 적용
- 효율적인 처리를 위해 함수들을 파이프라인같이 붙여서 중간결과를 별도로 산출하지 않고 연이어 처리

- map(), collect()를 파이프라인으로 처리
```
wordsLength = wordsRdd\
    .map(len)\
    .collect()
print wordsLength
```
[2, 2]

### 파일에 쓰기
- list는 RDD로 만들어 로컬 파일에 쓰게 됨.
- RDD는 디렉토리가 만들어지고 그 안에 내용이 쓰이게 됨.

- 파일로 쓰이려면 rdd.coalesce()를 사용
```
spark.sparkContext.parallelize(upper2list).saveAsTextFile("data/ds_spark_wiki_out")

_rdd=spark.sparkContext.textFile("data/ds_spark_wiki_out")
_rdd.collect()
```
[u"['A', 'LINE']", u"['THIS', 'IS']"]
	- RDD는 육안으로 보기 어려운 구조로 저장
	- 작업을 중단하거나 종료할 때 RDD로 저장하면 로컬에 그대로 보존되어서 다시 끌어쓸 수 있음.

### groupBy
- transformation 함수
- Pair, unpaired RDD에 모두 사용할 수 있지만, 주로 unpaired RDD에 많이 쓰임.
- 데이터를 딕셔너리처럼 만들어서 키를 선택하여 사용할 수 잇는 장점이 있음.
- groupByKey()와 비교해서 상대적으로 빠르지 않음.



- 앞 2글자를 key로 사용해서, groupBy()를 사용 가능
- 결과는 key-value로 생성되고, value는 iterator로 읽을 수 있음.
```
myRdd2.take(10)
```
[u'Wikipedia',
 u'Apache Spark is an open source cluster computing framework.',
 u'\uc544\ud30c\uce58 \uc2a4\ud30c\ud06c\ub294 \uc624\ud508 \uc18c\uc2a4 \ud074\ub7ec\uc2a4\ud130 \ucef4\ud4e8\ud305 \ud504\ub808\uc784\uc6cc\ud06c\uc774\ub2e4.',
 u'Apache Spark Apache Spark Apache Spark Apache Spark',
 u'\uc544\ud30c\uce58 \uc2a4\ud30c\ud06c \uc544\ud30c\uce58 \uc2a4\ud30c\ud06c \uc544\ud30c\uce58 \uc2a4\ud30c\ud06c \uc544\ud30c\uce58 \uc2a4\ud30c\ud06c',
 u"Originally developed at the University of California, Berkeley's AMPLab,",
 u'the Spark codebase was later donated to the Apache Software Foundation,',
 u'which has maintained it since.',
 u'Spark provides an interface for programming entire clusters with',
 u'implicit data parallelism and fault-tolerance.']

- 앞 2글자로 grouping
```
#myRdd_group=myRdd2.flatMap(lambda x:x.split()).groupBy(lambda x:w[0:2])
myRdd_group=myRdd2.groupBy(lambda x:x[0:2])

for (k,v) in myRdd_group.collect():
    for eachValue in v:
        print k, eachValue
    print "-----"
```
아파 아파치 스파크는 오픈 소스 클러스터 컴퓨팅 프레임워크이다.
아파 아파치 스파크 아파치 스파크 아파치 스파크 아파치 스파크
```
-----
im implicit data parallelism and fault-tolerance.
-----
th the Spark codebase was later donated to the Apache Software Foundation,
-----
Wi Wikipedia
-----
Ap Apache Spark is an open source cluster computing framework.
Ap Apache Spark Apache Spark Apache Spark Apache Spark
-----
Sp Spark provides an interface for programming entire clusters with
-----
Or Originally developed at the University of California, Berkeley's AMPLab,
-----
wh which has maintained it since.
-----
```
- 다음 데이터에 groupBy()를 적용하기
- 먼저 SparkContext parallize() 함수를 사용하여 리스트에서 RDD를 생성
```
_testList=[("key1",1),("key1",1),("key1",1),("key2",1),("key2",1),
           ("key1",1),("key2",1),
           ("key1",1),("key1",1),("key2",1),("key2",1)]
_testRdd=spark.sparkContext.parallelize(_testList)
```

- x[0]=("key1",1)은 첫 요소인 key를 groupBy()로 구분하여 각 key1, key2별로 묶기.
- groupByKey()의 결과는 ResultIterable ( 객체 그대로 볼 수 X)
```
_testRdd.groupBy(lambda x:x[0]).collect()
```
[('key2', <pyspark.resultiterable.ResultIterable at 0x7f08b316ced0>),
 ('key1', <pyspark.resultiterable.ResultIterable at 0x7f08b3187350>)]



