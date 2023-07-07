import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.collections.ArrayList
import kotlin.collections.HashMap

fun main() {
    val buffer = BufferedReader(InputStreamReader(System.`in`))
    val p = buffer.readLine()!!.toInt()
    val fees = ArrayList<Int>()
    for (i in 0 until p) {
        val list = buffer.readLine()!!.split(" ").map { it.toInt() }
        val hash = HashMap<Int, Int>()

        for (i in list) {
            if (hash[i] == 0 || hash[i] == null) {
                hash[i] = 1
            } else {
                hash[i] = hash[i]!!+1
            }
        }


        val reversedHash = hash.toSortedMap(compareBy<Int> { it }.reversed())

        if (reversedHash.containsValue(2)) {
            val response = reversedHash.filter { it.value == 2 }
            val answer = response.keys.first()
            fees.add(1000 + (answer)*100)
        } else if (reversedHash.containsValue(3)) {
            val response = reversedHash.filter { it.value == 3 }
            val answer = response.keys.first()
            fees.add(10000 + (answer)*1000)
        } else {
            val response = reversedHash.keys.first()
            fees.add(response * 100)
        }
    }

    fees.sortDescending()
    print(fees[0])
}