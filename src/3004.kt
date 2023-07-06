import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val buffer = BufferedReader(InputStreamReader(System.`in`))
    val n = buffer.readLine()!!.toInt()

    var cut = 1
    var sum = 1
    for (i in 1 .. n) {

        if (i % 2 == 0) {
            cut += 1
        }
        sum += cut
    }
    print(sum)
}