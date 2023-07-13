import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.collections.HashMap

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val achievement = this.readLine()!!

    val achievements = HashMap<String, Double>()
    achievements.put("A+", 4.3)
    achievements.put("A0", 4.0)
    achievements.put("A-", 3.7)
    achievements.put("B+", 3.3)
    achievements.put("B0", 3.0)
    achievements.put("B-", 2.7)
    achievements.put("C+", 2.3)
    achievements.put("C0", 2.0)
    achievements.put("C-", 1.7)
    achievements.put("D+", 1.3)
    achievements.put("D0", 1.0)
    achievements.put("D-", 0.7)
    achievements.put("F", 0.0)


    print(achievements[achievement])
}