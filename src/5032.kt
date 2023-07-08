import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val buffer = BufferedReader(InputStreamReader(System.`in`))
    val (e, f, c) = buffer.readLine()!!.split(" ").map { it.toInt() }
    var sum = e + f
    var count = 0
    while (true) {
       if (sum == 0 || sum/c == 0) break
        sum -= c-1
        count ++
    }
    return print(count)
}