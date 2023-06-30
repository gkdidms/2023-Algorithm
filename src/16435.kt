import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val buffer = BufferedReader(InputStreamReader(System.`in`))
    var (quantity, length) = buffer.readLine().split(" ").map { it.toInt() }
    val fruit = buffer.readLine().split(" ").map { it.toInt() }.sorted()

    for (i in 0 until quantity) {
        if (fruit[i] <= length) {
            length += 1
        }
    }

    print(length)
}