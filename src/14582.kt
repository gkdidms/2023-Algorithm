import java.io.BufferedReader
import java.io.InputStream
import java.io.InputStreamReader
import java.util.*
import kotlin.math.hypot

fun main() {
    val buffer = BufferedReader(InputStreamReader(System.`in`))
    val jamis = buffer.readLine()!!.toString().split(" ")
    val startLink = buffer.readLine()!!.toString().split(" ")

    var jamisSum = 0
    var startLinkSUm = 0
    var jamisCount = 0
    var startLinkCount = 0
    for(i in 0 until jamis.size*2) {

        if (i % 2 == 0) {
            jamisSum += jamis[jamisCount].toInt()
            jamisCount += 1
        } else {
            startLinkSUm += startLink[startLinkCount].toInt()
            startLinkCount += 1
        }
        if (jamisSum > startLinkSUm) {
            return print("Yes")
        }
    }
    return print("No")
}