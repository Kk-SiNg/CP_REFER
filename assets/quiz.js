/**
 * Quiz component for CP lessons.
 * Usage: Add class="quiz-option" to options, data-correct="true" to the right answer.
 * Each quiz block should have class="quiz" with a .quiz-feedback child.
 */
document.addEventListener('DOMContentLoaded', () => {
  document.querySelectorAll('.quiz').forEach(quiz => {
    const options = quiz.querySelectorAll('.quiz-option');
    const feedback = quiz.querySelector('.quiz-feedback');
    let answered = false;

    options.forEach(opt => {
      opt.addEventListener('click', () => {
        if (answered) return;
        answered = true;

        const isCorrect = opt.dataset.correct === 'true';
        opt.classList.add(isCorrect ? 'correct' : 'incorrect');

        // Reveal the correct answer
        options.forEach(o => {
          if (o.dataset.correct === 'true') o.classList.add('correct');
          o.style.cursor = 'default';
        });

        if (feedback) {
          feedback.classList.add('show');
          feedback.classList.add(isCorrect ? 'correct-feedback' : 'incorrect-feedback');
          feedback.textContent = isCorrect
            ? feedback.dataset.correct || '✓ Correct!'
            : feedback.dataset.incorrect || '✗ Not quite. See the highlighted answer above.';
        }
      });
    });
  });
});
