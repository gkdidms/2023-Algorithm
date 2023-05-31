/*어떤 자연수 p와 q가 있을 때, 만일 p를 q로 나누었을 때 나머지가 0이면 q는 p의 약수이다.

6을 예로 들면

6 ÷ 1 = 6 … 0
6 ÷ 2 = 3 … 0
6 ÷ 3 = 2 … 0
6 ÷ 4 = 1 … 2
6 ÷ 5 = 1 … 1
6 ÷ 6 = 1 … 0
그래서 6의 약수는 1, 2, 3, 6, 총 네 개이다.

두 개의 자연수 N과 K가 주어졌을 때, N의 약수들 중 K번째로 작은 수를 출력하는 프로그램을 작성하시오.*/
import java.util.*

fun main(args: Array<String>) {
    val read = readLine()!!.split(" ")
    val n = read[0].toInt()
    val m = read[1].toInt()
    var list = ArrayList<Int>()
    for (i in 1 .. n) {
        if (n % i == 0) {
            list.add(i)
        }
    }

    list.sort()

    if (list.size < m) println(0)
    else {
        println(list[m-1])
    }

}