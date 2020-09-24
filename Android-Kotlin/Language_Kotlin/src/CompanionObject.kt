class Book private constructor(val id: Int, val name: String){

    // companion object의 역할 : private property나 메소드를 읽어올 수 있게 해줌 (= 자바의 static)
    // 이름도 설정 가능
    // 상속도 가능(By interface)
    companion object BookFactory: IdProvider {
        override fun getId(): Int {
            return 444
        }

        override fun getName(): String {
            return "my book"
        }
        val newBook = "neww"
        fun create() = Book(getId(), getName())
    }
}

interface IdProvider {
    fun getId() : Int
    fun getName() : String
}

fun main(){
//    val book = Book()   // 이 구문은 클래스가 private이라서 에러남
    val book = Book.create()

    val bookId = Book.BookFactory.getId()
    val bookName = Book.BookFactory.getName()
//    println("${bookId} ${bookName}")
    println("${book.id} ${book.name}")
}