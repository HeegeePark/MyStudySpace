/*
 Expression(식) : 어떠한 값을 내포하고 있는 식 또는 표현식(Expression들은 함수의 매개변수로 사용될 수 있고, 함수의 반환값으로도 사용 가능)
     ex: 숫자, 문자열, 산술식 , 함수 리턴값(sum(a,b)), 변
 Statement(문장) : 어떠한 작업을 수행하는 문장 혹은 상태
     ex: 변수 선언(int a), 변수에 값 할당, 조건문, 반복문 등
 Statement이면서 Expression도 되는 경우 : a++

 자바는 Expression을 단독으로 만들 수 없음. 그래서 return 형식도 Statement
 코틀린은 모든 함수는 Expression 형태라 return이 없더라도 사실 Unit을 반환하고 있음. 그래서 당연 Expression 단독 사용 가능
 */
fun main() {
    stringTemplete()
    maxBy2(2,3)
    array()
    nullCheck()

}

// 1. String Templete
fun stringTemplete() {
    val name = "Heegee"
    val lastName = "Park"
    println("my name is ${name + lastName} I'm 23")

    println("is this true? ${1==0}")
    println("this is 2\$a")     // $ 출력하는법
}

// 2. 조건식(한줄로 조건 함수 또는 변수에 when 선언 가능)
fun maxBy2(a: Int, b: Int) = if(a>b) a else b

fun checkNum(score: Int) {
    var b = when(score){
        1 -> 1
        2 -> 2
        else -> 3
    }
}

// 3. Array and List
// Array(메모리가 미리 할당되어 나오므로 사이즈가 정해져 있음, 기본적으로 원소 값 변경 가능-> mutable)
// List 1.List 2.MutableList(수정가능) = ArrayList
fun array() {
    val array = arrayOf(1,2,3)
    val list = listOf(1,2,3)

    val array2 = arrayOf(1, "d", 3.4f)
    val list2 = listOf(1, "d", 11L)

    array[0] = 3 // 가능
    // list[0] = 2 -> immutable이라 원소 값 변경 불가능
    var result = list.get(0) // List는 인터페이스라 값을 불러와 변수에 할당은 가능

    val arrayList = arrayListOf<Int>()      // arrayList의 참조값(주소값)이 바뀌지 않으므로 val 변수 사용 가능
    arrayList.add(10)
    arrayList.add(20)
    arrayList[0] = 20
}

// 4. For
fun forAndWhile() {
    // i in 0..100 : 0부터 100까지
    // i in 0 until 100 : 0부터 99까지
    // i in 0..100 step 2 : i+=2하면서 0부터 100까지
    // i in 100 downTo 1 : i--하면서 0부터 100까지

    // index 함께 사용하는 반복문
    val students = arrayListOf("hg","ts")
    for ((index, name) in students.withIndex()) {
        println("${index+1}번째 학생: ${name}")
    }
}

// 5. Nullable / NonNull
fun nullCheck() {
    // NPE : Null Pointer Exception
    // 코틀린의 장점, 컴파일 시 미리 알려준다. 하지만 자바는 실행을 해야만 NPE 발생 여부 알 수 있음

    var name = "heegee"     // NonNull
    var nullName: String? = null    // nullable

    var nameInUpperCase = name.toUpperCase()
    var nullNameInUpperCase = nullName?.toUpperCase()       // ?를 넣어서 null이 아닐때만 upper, null이면 null 반환

    // ?: (엘비스 프레슬리 연산자)
    val lastName: String? = null
    val fullName = name + " " + (lastName?: "No lastName")      // 변수?: a -> 변수가 null이면 a 반환
    println(fullName)
}
fun ignoreNulls(str: String?) {
    //!! : 이 변수는 nullable이지만 여기서는 절대 null일리가 없어!! 라는 뜻
    // 웬만하면 자주 사용 지양할 것
    val mNotNull : String = str!!
    val upper = mNotNull.toUpperCase()

    // let함수
    val email: String? = "hg6259@gmail.com"
    // 자신의 리시버 객체(email)가 null이 아닐 시, 람다식 let 내부로 옮겨 실행
    email?.let {
        println("my email is ${it}")        // it = email
    }
}

