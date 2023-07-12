import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val (n,m) = this.readLine()!!.split(" ").map { it.toLong() }
    if (n < m) {
        print(m-n)
    } else {
        print(n-m)
    }
}