// 1. Lambda
// 람다식은 우리가 마치 Value 처럼 다룰 수 있는 익명함수(자바에서 흔히 쓰이는)이다.
// 1) 메소드의 파라미터로 넘기기 가능
// 2) return 값으로 사용 가능

// 람다의 기본 정의
//val lambdaName : Type = {argumentList -> codeBody}
    // argumentList는 파라미터

val square : (Int) -> (Int) = {number -> number*number}

// return이 없으면 unit 반환
// 파라미터 안에서 타입 선언 가능
val nameAge = {name: String, age: Int ->
    "my name is ${name}, I'm ${age}"
}

// 확장함수 (뭔가 추가하는)
val pizzaIsGreat: String.() -> String = {
    this + " Pizza is great"
}
fun extendString(name: String, age: Int) : String {
    // this = 이 확장함수를 사용하는 변수("String".(Int))
    // it = 이 확장함수를 사용하는 변수의 파라미터(String."(Int)")
    val introduceMyself: String.(Int) -> String = {
        "I am ${this} and ${it} years old"
    }
    return name.introduceMyself(age)
}

// 람다의 Return
val calculateGrade: (Int) -> String = {
    when(it) {
        in 0..40 -> "fail"
        in 41..70 -> "pass"
        in 71..100 -> "perfect"
        else -> "Error"     // return이 무조건 String으로 반환해야하므로 else 꼭 챙겨주기
    }
}

// 람다를 표현하는 여러가지 방법
fun invokeLambda(lambda : (Double) -> Boolean) : Boolean {
    return lambda(5.2343)
}

fun main() {
    println(square(12))
    println(nameAge("hg",23))

    val a = "heegee said"
    println(a.pizzaIsGreat())
    println(extendString("heegee",23))

    println(calculateGrade(90))
    println(calculateGrade(910))

    val lambda = {number: Double ->
        number == 4.3212
    }
    println(invokeLambda(lambda))
    println(invokeLambda({it > 3.22}))      // 여기서 it은 invokeLambda 함수의 파라미터 람다의 하나뿐인 파라미터(Double)
//    println(invokeLambda{it > 3.22})    // 위 코드와 동일한 코드 (마지막 파라미터가 람다식일떼 가능)
}
