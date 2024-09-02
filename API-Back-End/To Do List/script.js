function addTask() {
  const taskInput = document.getElementById('taskInput');
  const taskValue = taskInput.value.trim();

  if (taskValue) {
      const taskList = document.getElementById('taskList');

      const li = document.createElement('li');
      li.textContent = taskValue;

      const removeButton = document.createElement('button');
      removeButton.textContent = 'Remover';
      removeButton.className = 'remove-btn';
      removeButton.onclick = () => {
          taskList.removeChild(li);
      };

      li.appendChild(removeButton);
      taskList.appendChild(li);

      taskInput.value = '';
  }
}


document.getElementById('taskInput').addEventListener('keypress', (e) => {
  if (e.key === 'Enter') {
      addTask();
  }
});
