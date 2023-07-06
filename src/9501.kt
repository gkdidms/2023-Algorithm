import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.collections.ArrayList

fun main() {
    val buffer = BufferedReader(InputStreamReader(System.`in`))
    val testCase = buffer.readLine()!!.toInt()

    repeat(testCase) {
        val (quantity, distance) = buffer.readLine()!!.split(" ").map { it.toInt() }
        var count = 0

        repeat(quantity) {
            val (v, f, c) = buffer.readLine()!!.split(" ").map { it.toFloat() }
            if (v*(f/c) >= distance) {
                count ++
            }
        }
        println(count)
    }
}