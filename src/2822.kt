
import java.util.*
import kotlin.collections.*
import kotlin.collections.HashMap

fun main() {
    var fullScore = 0
    var scores = mutableMapOf<Int, Int>() // key = 점 value = 문
    for (i in 1 until 9) {
        val a = readLine()!!.toInt()
        scores[a] = i
    }

    val list = scores.toSortedMap(compareBy<Int> { it }.reversed())

    var count = 0
    val valueList = ArrayList<Int>()
    list.keys.forEach {
        if (count >= 5) {
            println(fullScore)
            valueList.sort()
            for ( i in valueList) {
                print("$i ")
            }
            return
        }
        fullScore += it
        valueList.add(list[it]!!)
        count += 1
    }
}
