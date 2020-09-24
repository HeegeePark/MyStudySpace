// 오브젝트 클래스는 한 번의 실행에 오직 하나의 객체만 생성됌.
// Singleton Pattern
// 장점 : 불필요한 메모리 사용 방지
object CarFactory {
    val cars = mutableListOf<Car>()
    fun makeCar(horsePower: Int): Car {
        val car = Car(horsePower)
        cars.add(car)
        return car
    }
}

data class Car(val horsePower : Int)

fun main() {
    // 딱 하나의 객체인 CarFactory를 사용
    val car = CarFactory.makeCar(10)
    val car2 = CarFactory.makeCar(200)

    println(car)
    println(car2)
    println(CarFactory.cars.size.toString())
}