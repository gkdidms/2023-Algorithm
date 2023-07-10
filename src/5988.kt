import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val k = this.readLine()!!.toInt()

    repeat(k) {
        val n = this.readLine()!!.chunked(1).map { it.toInt() }
        if (n[n.lastIndex] % 2 == 0) println("even")
        else println("odd")
    }


}