class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        pre = []
        i = 0
        
        while i < len(words):
            cnt, spaces, wds, j = 0, 0, 0, i
            while j < len(words) and cnt < maxWidth:
                curr = len(words[j]) + 1
                if curr + cnt <= maxWidth:
                    spaces += 1; wds += 1; cnt += curr; j += 1
                elif curr + cnt - 1 == maxWidth:
                    cnt += curr - 1; wds += 1; j += 1; break
                else:
                    break
            spaces += (maxWidth - cnt)
            pre.append((spaces, wds))
            i = j

        ans, prev = [], -1

        for i, (total_spaces, wds) in enumerate(pre):
            gap_count = max(1, wds - 1)
            sp = total_spaces // gap_count
            rem = total_spaces % gap_count

            if i == len(pre) - 1: # Last Line
                line_words = words[prev + 1 : prev + 1 + wds]
                s = " ".join(line_words)
                ans.append(s + " " * (maxWidth - len(s)))
                break

            if wds == 1: # Single-word Line
                ans.append(words[prev + 1] + " " * total_spaces)
                prev += 1
                continue

            s = "" # Normal Line
            for j in range(prev + 1, prev + wds):
                s += words[j]
                if len(s) == maxWidth: continue
                extra = 1 if rem > 0 else 0
                s += " " * (sp + extra)
                rem -= extra
            if prev + wds < len(words):
                s += words[prev + wds]
            ans.append(s)
            prev += wds

        return ans