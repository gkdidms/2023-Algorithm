import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() = with(BufferedReader(InputStreamReader(System.`in`))){
    val s = this.readLine()!!.toDouble()

    var n = 0
    var sum = 0.0
    while (true) {
        n += 1
        sum += n
        if (s == sum) break
        else if (s < sum) {n -= 1; break}
    }

    println(n)
}