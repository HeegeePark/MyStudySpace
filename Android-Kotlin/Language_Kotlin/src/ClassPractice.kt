// 주 생성자 선언(constructor써도 되고 안써도 되고(like 함수 파라미))
//class Human constructor(val name: String = "Anonymous"){
open class Human(val name: String = "Anonymous"){
    // 부 생성자
    // 주 생성자의 위임받아야 함. -> this(name)
    constructor(name: String, age: Int) : this(name) {
        println("my name is ${name}, age is ${age}")
    }

    // 주 생성자의 일부이므로, 객체 생성과 동시에 같이 실행(생성 시 바로 실행)
    // 부 생성자를 쓰더라도 init을 제일 먼저 실
    init {
        println("init")
    }
    fun eatingCake() {
        println("뇸")
    }
    open fun singASong() {
        println("yeahhhh")
    }
}

// 클래스 상속
// 상속 가능하려면 부모 클래스를 open class로 해줘야 가능
class Korean: Human() {
    // 함수도 open을 해줘야 override 가능
    override fun singASong() {
        super.singASong()
        println("얼씨구나")
    }

}

fun main() {
    // 객체 생성
    val human = Human("heegee")
    val stranger = Human()      // 생성자에 default값이 선언되어있어서, 객체 생성할 때 파라미터를 안넘겨줘도 에러X행
    val mom = Human("ays",52)

    human.eatingCake()

    val korean = Korean()
}
