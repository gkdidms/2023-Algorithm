import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.collections.HashMap
import kotlin.math.absoluteValue

fun main() {
    val buffer = BufferedReader(InputStreamReader(System.`in`))
    val map = HashMap<Int, Int>()
    for (i in 1 .. 5) {
        val p = buffer.readLine()!!.split(" ").map { it.toInt() }
        map[p.sum()] = i
    }

    val sortedMap = map.toSortedMap(compareBy<Int> { it }.reversed())

    print("${sortedMap[sortedMap.firstKey()]} ${sortedMap.firstKey()}")
}