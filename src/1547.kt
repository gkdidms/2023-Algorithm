import java.util.*
import kotlin.collections.HashMap

fun main() {
    val m = readLine()!!.toInt()
    val cup = HashMap<Int, Int>() // <컵 번호 , 순서>
    cup.put(1,1)
    cup.put(2,2)
    cup.put(3,3)
    for (i in 0 until m) {
        val input = readLine()!!.split(" ")
        val first = cup[input[1].toInt()]!!.toInt()
        val second =  cup[input[0].toInt()]!!.toInt()
        cup[input[0].toInt()] = first
        cup[input[1].toInt()] = second
    }

    val response = cup.filter { it.value == 1 }
    response.keys.forEach { print(it) }

}